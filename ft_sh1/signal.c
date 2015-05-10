#include "sh1.h"

void ft_exit()
{
	ft_putstr("\n$>");
	exit(0);
}

void	gestion_signal(int cons)
{
	void	*ft;
	int		i;

	i = 0;
	ft = sighandler;
	if (cons == 1)
		ft = ft_exit;
	signal(SIGFPE, ft);
	signal(SIGSEGV, ft);
	signal(SIGABRT, ft);
	signal(SIGTERM, ft);
	signal(SIGTSTP, ft);
	signal(SIGINT, ft);
}

void sighandler(int signum)
{
	ft_putstr("\nCaught signal : ");
	ft_putnbr(signum);
	ft_putendl("coming out...");
	if (signum == SIGINT)
		ft_putstr("SIGINT: Interupt\n");
	if (signum == SIGTERM)
		ft_putstr("SIGTERM: terminate\n");
	if (signum == SIGFPE)
		ft_putstr("SIGFPE: floating point exeption\n");
	if (signum == SIGABRT)
		ft_putstr("SIGABRT: Abnormal termination\n");
	if (signum == SIGSEGV)
		ft_putstr("SIGSEG: Segmentation violation\n");
	if (signum == SIGTSTP)
		ft_putstr("SIGTSTP: sorry, you are not allowed to do so.\n");
	sh_prompt(0);
//	exit(0);
}
