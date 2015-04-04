#include "sh1.h"

void	gestion_signal(void)
{
	signal(SIGINT, sighandler);
}

void sighandler(int signum)
{
	printf("\nCaught signal %d, coming out...\n", signum);
	exit(1);
}
