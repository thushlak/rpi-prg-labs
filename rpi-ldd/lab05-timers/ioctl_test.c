#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "rw_ioctl.h"

#define DEVICE_PATH "/dev/rw_driver"

int main(void)
{
    int fd;
    int value;

    fd = open(DEVICE_PATH, O_RDWR);

    if (fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    if (ioctl(fd, IOCTL_GET_BUFFER_SIZE, &value) < 0) {
        perror("IOCTL_GET_BUFFER_SIZE");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Current active buffer size: %d\n", value);

    value = 128;

    if (ioctl(fd, IOCTL_SET_BUFFER_SIZE, &value) < 0) {
        perror("IOCTL_SET_BUFFER_SIZE");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Active buffer size changed to: %d\n", value);

    if (ioctl(fd, IOCTL_GET_DRIVER_VERSION, &value) < 0) {
        perror("IOCTL_GET_DRIVER_VERSION");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Driver version: %d\n", value);

    if (ioctl(fd, IOCTL_CLEAR_BUFFER) < 0) {
        perror("IOCTL_CLEAR_BUFFER");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Driver buffer cleared\n");

    close(fd);

    return EXIT_SUCCESS;
}
