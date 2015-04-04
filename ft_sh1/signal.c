#include "sh1.h"

void	gestion_signal()
{
	signal(SIGFPE, sighandler);
	signal(SIGTERM, sighandler);
	signal(SIGINT, sighandler);
	signal(SIGILL, sighandler);
	signal(SIGABRT, sighandler);
	signal(SIGSEGV, sighandler);
}

void sighandler(int signum)
{
	printf("\nCaught signal %d, coming out...\n", signum);
	if (signum == SIGFPE)
		printf("SIGFPE: floating point exeption\n");
	if (signum == SIGILL)
		printf("SIGILL: Illegal Instruction\n");
	if (signum == SIGABRT)
		printf("SIGABRT: Abnormal termination\n");
	if (signum == SIGSEGV)
		printf("SIGSEG: Segmentation violation\n");
	if (signum == SIGTERM)
		printf("SIGTERM: terminate\n");
	if (signum == SIGINT)
		printf("SIGINT: Interupt, (?continue with bg?)\n");
	exit(0);
}
