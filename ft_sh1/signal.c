#include "sh1.h"

void ft_exit()
{
	ft_putstr("\n$>");
	exit(0);
}

void	gestion_signal(int cons)
{
	void	*ft;

	ft = sighandler;
	if (cons == 1)
		ft = ft_exit;
	signal(SIGFPE, ft);
	signal(SIGTERM, ft);
	signal(SIGINT, ft);
	signal(SIGILL, ft);
	signal(SIGABRT, ft);
	signal(SIGSEGV, ft);
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
		printf("SIGINT: Interupt\n");
//	exit(0);
}
