#include "sh1.h"

int main(int argc, char **argv, char **env)
{
	int		i = 0;

	
	ft_putnbr(argc);
	ft_putendl("");
	while (argv[i] != NULL)
	{
		ft_putendl(argv[i]);
		i++;
	}
	ft_putendl("\n\n");
	env = get_env(env, 's');
	while ((ret = get_next_command(&tab)))
}
