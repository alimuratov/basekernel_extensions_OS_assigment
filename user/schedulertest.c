#include "library/syscalls.h"

int main() {
    const char *exec[5] = {"bin/process1.exe", "bin/process2.exe", "bin/process3.exe", "bin/process4.exe", "bin/process5.exe"};
    const char *pr[5] = {"9", "7", "2", "1", "5"};

	
	for (int i = 0; i < 5; i++) {
	    const char *argv[2];
	    argv[0] = exec[i];
	    argv[1] = pr[i];
	    int argc = 2;
	    int pfd = syscall_open_file(KNO_STDDIR, exec[i], 0, 0);
	    if (pfd >= 0) {
		int pid = syscall_process_run(pfd, argc, argv);
		if (pid > 0) {
		    // printf("started processsss %d\n", pid);
		} else {
		    printf("couldn't run %s: %s\n", argv[0], strerror(-pid));
		}
		syscall_object_close(pfd);
	    } else {
		printf("couldn't find %s: %s\n", argv[0], strerror(-pfd));
	    }
	}
	
	for (int i = 0; i < 5; i++) {
	    syscall_process_wakeup();
	}
}	

