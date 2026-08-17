#ifndef RW_IOCTL_H
#define RW_IOCTL_H

#include <linux/ioctl.h>

#define IOCTL_MAGIC 'R'

#define IOCTL_CLEAR_BUFFER \
    _IO(IOCTL_MAGIC, 1)

#define IOCTL_GET_BUFFER_SIZE \
    _IOR(IOCTL_MAGIC, 2, int)

#define IOCTL_SET_BUFFER_SIZE \
    _IOW(IOCTL_MAGIC, 3, int)

#define IOCTL_GET_DRIVER_VERSION \
    _IOR(IOCTL_MAGIC, 4, int)

#endif
