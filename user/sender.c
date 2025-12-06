#include "library/syscalls.h"
#include "library/string.h"
#include "library/stdio.h"
#include "library/kernel_object_string.h"
#include "library/nwindow.h"
#include "library/errno.h"

int main() {
    char *pathname = "newfolder";
    char *filename = "newfile";

    printf("\n");
    printf("   Creating a new file...\n");
    int res = syscall_make_named_pipe(pathname, filename);
    if (res) printf("   File successfully created\n");
    else printf("   File not created\n");
    printf("\n");

    printf("Sender:\n");
    printf("   Opening the named pipe...\n");
    int fd = syscall_open_named_pipe(pathname, filename);
    if (fd > 0) {
        printf("   Named pipe opened successfully\n");
    } else {
        printf("   Named pipe not opened\n");
    }
    char buffer[] = "Hello World\n";
    printf("   Sending byte stream: %s", buffer);
    //printf("Writing info...\n");
    int bytes_written = syscall_object_write(fd, buffer, strlen(buffer), KERNEL_FLAGS_WRITE);
    printf("   Bytes written: %d\n", bytes_written);
    printf("\n");
}