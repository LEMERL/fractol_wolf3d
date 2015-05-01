#include "sh1.h"

void	sh_fatal_error(char *msg);
int		built_in(t_env *strc_env, char **tab_line);
void	sh_cd(t_env *strc_env, char **arg);
void	gt_env(t_env *strc_env, char **env);
void	sh_boucle_lecture(t_env *strc);
int		sh_prompt();

int			main(int argc, char **argv, char **env)
{
	t_env	strc;
	(void)argc;
	(void)argv;

	gestion_signal(0);
	get_env(&strc, env);
	sh_boucle_lecture(&strc);
	return(0);
}

void	sh_boucle_lecture(t_env *strc)
{
	char	*line;
	int		status;
	int		ret;
	pid_t	pid;
	char	**tab_line;

	pid = 1;
	while(sh_prompt() && (ret = get_next_line(0, &line)) > 0)//change gnl par ((ret = get_command(0, &line)) > 0)
	{
		tab_line = ft_strsplit(line, ' ');
		if (built_in(strc, tab_line) == 0)
			if ((pid = fork()) < 0)
				sh_fatal_error("fork failled");
		if (pid == 0)
		{
			gestion_signal(1);
			get_command(strc, tab_line);
			exit(0);
		}
		if (pid > 0)
		{
			wait(&status);
			ft_putstr("\n$>");
		//	free_tab(tab_line);
			free(line);
		}
	}
}

void		sh_unset_env(char *str, t_env *env);

int		built_in(t_env *strc_env, char **tab_line)
{
	int		i;

	i = 0;
	printf("test of the built_in command:\n");
	(void)strc_env;
	(void)tab_line;
	if (ft_strcmp(tab_line[0], "exit") == 0)
	{
		ft_putendl("goodbye, see you soooooon");
		exit(1);
	}
	else if (ft_strcmp(tab_line[0], "cd") == 0)
	{
		printf("so it is CD :D \n");
		sh_cd(strc_env, tab_line + 1);
		return (1);
	}
	else if (ft_strcmp(tab_line[0], "env") == 0)
	{
		printf("so it is ENV :D \n");
		print_env(strc_env->env);
		return (1);
	}
	else if (ft_strcmp(tab_line[0], "setenv") == 0)
	{
		printf("so it is SETENV :D \n");
		return (1);
	}
	else if (ft_strcmp(tab_line[0], "unsetenv") == 0)
	{
		while (tab_line[++i] != NULL)
			sh_unset_env(tab_line[i], strc_env);
		printf("so it is UNSETENV :D \n");
		return (1);
	}
	else
	return (0);
}

void		get_command(char **tab_line)
{
	if (tab_line[0][0] == '.' || tab_line[0][0] == '/' || tab_line[0][0] == '~')
		command_not_in_path(tab_line);
	else
		command_in_path(tab_line);
}

void		command_in_path(char **tab_cmd)
{
	char		*cmd;
	int			j;
	int			going;

	j = -1;
	going = 1;
	//built_in(strc_env, tab_line);
	if (ft_strcmp(tab_cmd[0], "exit") == 0)
		kill(0, SIGINT);
	cmd = (char*)ft_strnew(1024);
	while (going == 1 && strc_env->path[++j] != NULL)
	{
		ft_strclr(cmd);
		cmd = ft_strcat(cmd, strc_env->path[j]);
		cmd = ft_strcat(cmd, "/");
		cmd = ft_strcat(cmd, tab_line[0]);
		printf("command tested: %s\n", cmd);
		if (access(cmd, F_OK|X_OK) == 0)
			going = 0;
	}
	printf("command receveid: %s\n", tab_cmd[0]);
	if (going == 0)
	{
		printf("command executed: %s\n", cmd);
		execve(cmd, tab_cmd, strc_env->env);
	}
	else
	{
		printf("command not in the PATH: %s\n", tab_line[0]);
	}
	free(cmd);
	free(tab_line);
	(void)strc_env;
	return (NULL);
}
