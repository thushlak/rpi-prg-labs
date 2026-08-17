#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Thush");
MODULE_DESCRIPTION("Lab 3 - Read/Write Character Device Driver");
MODULE_VERSION("1.0");

#define DEVICE_NAME "rw_driver"
#define CLASS_NAME  "rw_class"
#define BUFFER_SIZE 256

static dev_t rw_dev;
static struct cdev rw_cdev;
static struct class *rw_class;
static struct device *rw_device;

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
    size_t bytes_to_copy;

    bytes_to_copy = min(count, (size_t)(BUFFER_SIZE - 1));

    if (copy_from_user(device_buffer,
                       user_buffer,
                       bytes_to_copy)) {
        pr_err("rw_driver: copy_from_user failed\n");
        return -EFAULT;
    }

    device_buffer[bytes_to_copy] = '\0';
    data_size = bytes_to_copy;
    *offset += bytes_to_copy;

    pr_info("rw_driver: wrote %zu bytes\n", bytes_to_copy);

    return bytes_to_copy;
}

static const struct file_operations rw_fops = {
    .owner   = THIS_MODULE,
    .open    = rw_open,
    .read    = rw_read,
    .write   = rw_write,
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

    pr_info("rw_driver: device created successfully\n");
    pr_info("rw_driver: module loaded\n");

    return 0;
}

static void __exit rw_driver_exit(void)
{
    device_destroy(rw_class, rw_dev);
    class_destroy(rw_class);
    cdev_del(&rw_cdev);
    unregister_chrdev_region(rw_dev, 1);

    pr_info("rw_driver: module unloaded\n");
}

module_init(rw_driver_init);
module_exit(rw_driver_exit);