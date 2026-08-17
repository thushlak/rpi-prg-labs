#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h> 
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Thush");
MODULE_DESCRIPTION("Basic Linux character device driver");
MODULE_VERSION("1.0");

#define DEVICE_NAME "hello_char"
#define CLASS_NAME  "hello_class"

static dev_t hello_dev;
static struct cdev hello_cdev;
static struct class *hello_class;
static struct device *hello_device;


static const char hello_message[] =
    "Hello from the Linux kernel character driver\n";

static ssize_t hello_read(struct file *file,
                          char __user *user_buffer,
                          size_t count,
                          loff_t *offset)
{
    size_t message_length = sizeof(hello_message) - 1;
    size_t bytes_to_copy;

    if (*offset >= message_length)
        return 0;

    bytes_to_copy = min(count,
                        message_length - (size_t)*offset);

    if (copy_to_user(user_buffer,
                     hello_message + *offset,
                     bytes_to_copy)) {
        return -EFAULT;
    }

    *offset += bytes_to_copy;

    pr_info("hello_char: read %zu bytes\n", bytes_to_copy);

    return bytes_to_copy;
}




static int hello_open(struct inode *inode, struct file *file)
{
    pr_info("hello_char: device opened\n");
    return 0;
}


static int hello_release(struct inode *inode, struct file *file)
{
    pr_info("hello_char: device closed\n");
    return 0;
}

static const struct file_operations hello_fops = {
    .owner = THIS_MODULE,
    .open = hello_open,
    .read    = hello_read,
    .release = hello_release,
};


static int __init hello_char_init(void)
{
    int ret;

    ret = alloc_chrdev_region(&hello_dev, 0, 1, DEVICE_NAME);
    if (ret < 0) {
        pr_err("hello_char: failed to allocate device number\n");
        return ret;
    }

    pr_info("hello_char: allocated major=%d minor=%d\n",
            MAJOR(hello_dev),
            MINOR(hello_dev));

    cdev_init(&hello_cdev, &hello_fops);
    hello_cdev.owner = THIS_MODULE;

    ret = cdev_add(&hello_cdev, hello_dev, 1);
    if (ret < 0) {
        pr_err("hello_char: failed to add cdev\n");
        unregister_chrdev_region(hello_dev, 1);
        return ret;
    }

    hello_class = class_create(CLASS_NAME);
    if (IS_ERR(hello_class)) {
        ret = PTR_ERR(hello_class);
        pr_err("hello_char: failed to create class\n");

        cdev_del(&hello_cdev);
        unregister_chrdev_region(hello_dev, 1);

        return ret;
    }

    hello_device = device_create(
        hello_class,
        NULL,
        hello_dev,
        NULL,
        DEVICE_NAME
    );

    if (IS_ERR(hello_device)) {
        ret = PTR_ERR(hello_device);
        pr_err("hello_char: failed to create device\n");

        class_destroy(hello_class);
        cdev_del(&hello_cdev);
        unregister_chrdev_region(hello_dev, 1);

        return ret;
    }

    pr_info("hello_char: module loaded successfully\n");

    return 0;
}


static void __exit hello_char_exit(void)
{
    device_destroy(hello_class, hello_dev);
    class_destroy(hello_class);
    cdev_del(&hello_cdev);
    unregister_chrdev_region(hello_dev, 1);

    pr_info("hello_char: module unloaded\n");
}




module_init(hello_char_init);
module_exit(hello_char_exit);
