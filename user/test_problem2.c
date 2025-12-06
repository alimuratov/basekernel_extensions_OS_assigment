#include "library/syscalls.h"

int main() {
    const char *exec[4] = {"bin/sender.exe", "bin/receiver.exe"};
    const char *pr[4] = {"2", "9"};

	
	for (int i = 0; i < 2; i++) {
	    const char *argv[2];
	    argv[0] = exec[i];
	    argv[1] = pr[i];
	    int argc = 2;
	    int pfd = syscall_open_file(KNO_STDDIR, exec[i], 0, 0);
	    if (pfd >= 0) {
		int pid = syscall_process_run(pfd, argc, argv);

		syscall_object_close(pfd);
	    } 
        else {
		    printf("couldn't find %s: %s\n", argv[0], strerror(-pfd));
	    }
	}
	
	for (int i = 0; i < 2; i++) {
	    syscall_process_wakeup();
	}
}	

