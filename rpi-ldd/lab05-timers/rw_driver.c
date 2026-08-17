#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include "rw_ioctl.h"
#define DRIVER_VERSION 1
#include <linux/timer.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Thush");
MODULE_DESCRIPTION("Lab 3 - Read/Write Character Device Driver");
MODULE_VERSION("1.0");

#define DEVICE_NAME "rw_driver"
#define CLASS_NAME  "rw_class"
#define BUFFER_SIZE 256
#define IOCTL_MAGIC 'R'

#define IOCTL_CLEAR_BUFFER \
    _IO(IOCTL_MAGIC, 1)

#define IOCTL_GET_BUFFER_SIZE \
    _IOR(IOCTL_MAGIC, 2, int)

#define IOCTL_SET_BUFFER_SIZE \
    _IOW(IOCTL_MAGIC, 3, int)

#define IOCTL_GET_DRIVER_VERSION \
    _IOR(IOCTL_MAGIC, 4, int)

#define DRIVER_VERSION 1



static dev_t rw_dev;
static struct cdev rw_cdev;
static struct class *rw_class;
static struct device *rw_device;
static struct timer_list rw_timer;
static size_t active_buffer_size = BUFFER_SIZE;

static char device_buffer[BUFFER_SIZE] =
    "Initial data from the kernel driver\n";

static size_t data_size =
    sizeof("Initial data from the kernel driver\n") - 1;

static int rw_open(struct inode *inode, struct file *file)
{
    pr_info("rw_driver: device opened\n");
    return 0;
}

static int rw_release(struct inode *inode, struct file *file)
{
    pr_info("rw_driver: device closed\n");
    return 0;
}

static ssize_t rw_read(struct file *file,
                       char __user *user_buffer,
                       size_t count,
                       loff_t *offset)
{
    size_t bytes_available;
    size_t bytes_to_copy;

    if (*offset >= data_size)
        return 0;

    bytes_available = data_size - (size_t)*offset;
    bytes_to_copy = min(count, bytes_available);

    if (copy_to_user(user_buffer,
                     device_buffer + *offset,
                     bytes_to_copy)) {
        pr_err("rw_driver: copy_to_user failed\n");
        return -EFAULT;
    }

    *offset += bytes_to_copy;

    pr_info("rw_driver: read %zu bytes\n", bytes_to_copy);

    return bytes_to_copy;
}

static ssize_t rw_write(struct file *file,
                        const char __user *user_buffer,
                        size_t count,
                        loff_t *offset)
{
    size_t space_available;
    size_t bytes_to_copy;

    if (*offset >= active_buffer_size - 1)
        return -ENOSPC;

    space_available =
        (active_buffer_size - 1) - (size_t)*offset;

    bytes_to_copy = min(count, space_available);

    if (copy_from_user(device_buffer + *offset,
                       user_buffer,
                       bytes_to_copy)) {
        pr_err("rw_driver: copy_from_user failed\n");
        return -EFAULT;
    }

    *offset += bytes_to_copy;
    data_size = (size_t)*offset;
    device_buffer[data_size] = '\0';

    mod_timer(&rw_timer,
          jiffies + msecs_to_jiffies(5000));

    pr_info("rw_driver: wrote %zu bytes\n",
            bytes_to_copy);

    return bytes_to_copy;
}

static long rw_ioctl(struct file *file,
                     unsigned int command,
                     unsigned long argument)
{
    int value;

    switch (command) {

    case IOCTL_CLEAR_BUFFER:
        data_size = 0;
        device_buffer[0] = '\0';

        pr_info("rw_driver: buffer cleared using ioctl\n");
        return 0;

    case IOCTL_GET_BUFFER_SIZE:
        value = (int)active_buffer_size;

        if (copy_to_user((int __user *)argument,
                         &value,
                         sizeof(value))) {
            pr_err("rw_driver: ioctl copy_to_user failed\n");
            return -EFAULT;
        }

        pr_info("rw_driver: returned buffer size %d\n", value);
        return 0;

    case IOCTL_SET_BUFFER_SIZE:
        if (copy_from_user(&value,
                           (int __user *)argument,
                           sizeof(value))) {
            pr_err("rw_driver: ioctl copy_from_user failed\n");
            return -EFAULT;
        }

        if (value <= 0 || value > BUFFER_SIZE) {
            pr_err("rw_driver: invalid buffer size %d\n", value);
            return -EINVAL;
        }

        active_buffer_size = value;

        if (data_size > active_buffer_size)
            data_size = active_buffer_size;

        device_buffer[data_size] = '\0';

        pr_info("rw_driver: active buffer size set to %d\n", value);
        return 0;

    case IOCTL_GET_DRIVER_VERSION:
        value = DRIVER_VERSION;

        if (copy_to_user((int __user *)argument,
                         &value,
                         sizeof(value))) {
            pr_err("rw_driver: version copy_to_user failed\n");
            return -EFAULT;
        }

        pr_info("rw_driver: returned driver version %d\n", value);
        return 0;

    default:
        pr_warn("rw_driver: unknown ioctl command 0x%x\n",
                command);
        return -ENOTTY;
    }
}

static void rw_timer_callback(struct timer_list *timer)
{
    pr_info("rw_driver: timer expired\n");
}

static const struct file_operations rw_fops = {
    .owner   = THIS_MODULE,
    .open    = rw_open,
    .read    = rw_read,
    .write   = rw_write,
    .unlocked_ioctl = rw_ioctl,
    .release = rw_release,
};

static int __init rw_driver_init(void)
{
    int ret;

    ret = alloc_chrdev_region(&rw_dev, 0, 1, DEVICE_NAME);

    if (ret < 0) {
        pr_err("rw_driver: failed to allocate device number\n");
        return ret;
    }

    pr_info("rw_driver: allocated Major=%d Minor=%d\n",
            MAJOR(rw_dev),
            MINOR(rw_dev));

    cdev_init(&rw_cdev, &rw_fops);
    rw_cdev.owner = THIS_MODULE;

    ret = cdev_add(&rw_cdev, rw_dev, 1);

    if (ret < 0) {
        pr_err("rw_driver: failed to register cdev\n");
        unregister_chrdev_region(rw_dev, 1);
        return ret;
    }

    pr_info("rw_driver: cdev registered successfully\n");

    rw_class = class_create(CLASS_NAME);

    if (IS_ERR(rw_class)) {
        ret = PTR_ERR(rw_class);

        pr_err("rw_driver: failed to create class\n");

        cdev_del(&rw_cdev);
        unregister_chrdev_region(rw_dev, 1);

        return ret;
    }

    rw_device = device_create(
        rw_class,
        NULL,
        rw_dev,
        NULL,
        DEVICE_NAME
    );

    if (IS_ERR(rw_device)) {
        ret = PTR_ERR(rw_device);

        pr_err("rw_driver: failed to create device\n");

        class_destroy(rw_class);
        cdev_del(&rw_cdev);
        unregister_chrdev_region(rw_dev, 1);

        return ret;
    }

    timer_setup(&rw_timer, rw_timer_callback, 0);

    pr_info("rw_driver: timer initialised\n");
    pr_info("rw_driver: device created successfully\n");
    pr_info("rw_driver: module loaded\n");

    return 0;
}

static void __exit rw_driver_exit(void)
{
    timer_delete_sync(&rw_timer);

    device_destroy(rw_class, rw_dev);
    class_destroy(rw_class);
    cdev_del(&rw_cdev);
    unregister_chrdev_region(rw_dev, 1);

    pr_info("rw_driver: module unloaded\n");
}

module_init(rw_driver_init);
module_exit(rw_driver_exit);