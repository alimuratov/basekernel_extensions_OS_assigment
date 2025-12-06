#include "library/syscalls.h"
#include "library/string.h"
#include "library/stdio.h"
#include "library/kernel_object_string.h"
#include "library/nwindow.h"
#include "library/errno.h"

int main() {
    char *pathname = "newfolder";
    char *filename = "newfile";

    printf("Receiver:\n");
    printf("   Opening the named pipe...\n");
    int fd = syscall_open_named_pipe(pathname, filename);
    if (fd > 0) {
        printf("   Named pipe opened successfully\n");
    } else {
        printf("   Named pipe not opened\n");
    }

    char buffer[20];
    int bytes_read = syscall_object_read(fd, buffer, 20, 0);
    printf("   Bytes read: %d\n", bytes_read);
    printf("   Byte stream read: %s\n", buffer);
}