#include "library/syscalls.h"

// invoked in test programs
void runForSeconds(int seconds) {
	unsigned int startTime; // seconds
	syscall_system_time(&startTime);
	unsigned int timeElapsed;
	do {
		syscall_system_time(&timeElapsed);
		timeElapsed -= startTime;
	} while(timeElapsed < seconds);
}

int main(void) {
	//syscall_process_wait();
	printf("Running process 1 (priority: 9)\n");
	runForSeconds(2);
	exit(0);
}
