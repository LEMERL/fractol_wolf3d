#include "sh1.h"

void	signal_in_fork(int value)
{
	ft_putstr("\nCaught signal : ");
	ft_putnbr(value);
	ft_putendl("coming out...");
	ft_putendl("goodbye");
	exit(value);
}

void signal_message(int signum)
{
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
	sh_prompt();
}

void	passif(int value)
{
	(void)value;
	sh_prompt();
}

void	gestion_signal(int value)
{
	void	*ft;
	int		i;

	i = 0;
	ft = signal_message;
	if (value == 1)
		ft = exit;
	else if (value == 2)
		ft = passif;
	signal(SIGFPE, ft);
	signal(SIGSEGV, ft);
	signal(SIGABRT, ft);
	signal(SIGTERM, ft);
	signal(SIGTSTP, ft);
	signal(SIGINT, ft);
}
