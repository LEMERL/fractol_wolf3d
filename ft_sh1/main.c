
#include "sh1.h"

void	sh_fatal_error(char *msg);
int		built_in(char **argv);
void	sh_cd(char **arg);
void	sh_boucle_lecture();

int		sh_prompt()
{
	ft_putendl("");
	ft_putstr(get_str_env("PWD"));
	ft_putendl(" : ");
	return (1);
}

int			main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;

	gestion_signal(0);
	get_env(env, 's');
	sh_boucle_lecture();
	return(0);
}

void	sh_boucle_lecture()
{
	char	*line;
	int		ret;
	pid_t	pid;
	char	**argv;

	pid = 1;
	while(sh_prompt() && (ret = get_next_line(0, &line)) > 0)//change gnl par ((ret = get_command(0, &line)) > 0)
	{
		argv = ft_strsplit(line, ' ');// " " << >> && || ~ \'/' + change $PATH par bonne valeur
		if (built_in(argv) == 0)
			pid = fork();
//				sh_fatal_error("fork failled");
		if (pid == 0)
		{
			gestion_signal(1);
			get_command(argv);
			exit(0);
		}
		if (pid > 0)
		{
			wait(NULL);
			free_tab(argv);
			free(line);
		}
	}
}

int		built_in(char **argv)
{
	int		i;

	i = 0;
	printf("test of the built_in command:\n");
	if (ft_strcmp(argv[0], "exit") == 0)
	{
		ft_putendl("goodbye, see you soooooon");
		exit(1);
	}
	else if (ft_strcmp(argv[0], "cd") == 0)
	{
		printf("so it is CD :D \n");
		sh_cd(argv);
		return (1);
	}
	else if (ft_strcmp(argv[0], "env") == 0)
	{
		printf("so it is ENV :D \n");
		print_env(get_env(NULL, 0));
		return (1);
	}
	else if (ft_strcmp(argv[0], "setenv") == 0)
	{
		printf("so it is SETENV :D \n");
		return (1);
	}
	else if (ft_strcmp(argv[0], "unsetenv") == 0)
	{
		while (argv[++i] != NULL)
			sh_unsetenv(argv);
		printf("so it is UNSETENV :D \n");
		return (1);
	}
	else
	return (0);
}

void		command_not_in_path(char **argv)
{
	if (access(argv[0], F_OK|X_OK) == 0)
		execve(argv[0], argv, get_env(NULL, 0));
}

void		command_in_path(char **tab_cmd);

void		get_command(char **argv)
{
	if (argv[0][0] == '.' || argv[0][0] == '/' || argv[0][0] == '~')
		command_not_in_path(argv);
	else
		command_in_path(argv);
}

void		command_in_path(char **tab_cmd)
{
	char		*cmd;
	int			j;
	int			going;
	char		**path;

	j = -1;
	going = 1;
	if ((path = get_addr_str_env("PATH")) == NULL)
		exit (-1);
	if (ft_strcmp(tab_cmd[0], "exit") == 0)
		kill(0, SIGINT);
	cmd = (char*)ft_strnew(ft_strlen(*path) + ft_strlen(tab_cmd[0] + 3));
	path = ft_strsplit(*path, ':');
	while (going == 1 && path[++j] != NULL)
	{
		ft_strclr(cmd);
		cmd = ft_strcat(cmd, path[j]);
		cmd = ft_strcat(cmd, "/");
		cmd = ft_strcat(cmd, tab_cmd[0]);
		printf("command tested: %s\n", cmd);
		if (access(cmd, F_OK|X_OK) == 0)
			going = 0;
	}
	printf("command receveid: %s\n", tab_cmd[0]);
	if (going == 0)
	{
		printf("command executed: %s\n", cmd);
		execve(cmd, tab_cmd, get_env(NULL, 0));
	}
	else
	{
		printf("command not in the PATH: %s\n", tab_cmd[0]);
	}
	free(cmd);
	free_tab(path);
}
