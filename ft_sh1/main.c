#include "sh1.h"

int			main(int argc, char **argv, char **env)
{
	t_env	strc_env;
	char	*line;
	int		status;
	int		ret;
	pid_t	pid;
	(void)argc;
	(void)argv;

//		gestion_signal();
	get_env(&strc_env, env);
	ft_putstr("$>");
	while((ret = get_next_line(0, &line)) > 0)
	{
		pid = fork();
		if (pid > 0)
		{
			wait(&status);
			ft_putstr("\n$>");
			free(line);
		}
		if (pid == 0)
		{
			get_command(&strc_env, line);
			exit(0);
		}
	}
//	if (pid > 0)
//		liberation(&strc_env);
	return(0);
}


void		built_in(t_env *strc_env, char **tab_line)
{
	(void)strc_env;
	(void)tab_line;
	if (ft_strcmp(tab_line[0], "exit"))
		exit(1);
/*	int		val;

	val = 0;
	if (ft_strcmp(tab_line[0], "exit"))
	{
		if (tab_line[1] != NULL)
			val = ft_atoi(tab_line[1]);
		exit(val);
	}
	if (ft_strcmp(tab_line[0], "cd"))
	{
//		if (tab_line[1] != NULL)
		//	cd();
		printf("we should be moving");
		exit(0);
	}*/
}

char		**get_command(t_env *strc_env, char *line)
{
	char		*cmd;
	char		**tab_line;
	int			j;
	int			going;

	tab_line = ft_strsplit(line, ' ');
/*	if (ft_strncmp(tab_line[0], "./", 2) == 0)
	{
		cmd = ft_strcat(cmd, (tab_line[0] + 2));
		going = 2;
	}
*/	
	j = -1;
	going = 1;
	//built_in(strc_env, tab_line);
	if (ft_strcmp(tab_line[0], "exit") == 0)
		kill(0, SIGINT);
	cmd = (char*)ft_strnew(1024);
	while (going == 1 && strc_env->path[++j] != NULL)
	{
		cmd = ft_strcat(strc_env->path[j], "/");
		cmd = ft_strcat(cmd, tab_line[0]);
		printf("command tested: %s\n", cmd);
		if (access(cmd, F_OK|X_OK) == 0)
			going = 0;
	}
	printf("line receveid: %s\n", line);
	printf("command receveid: %s\n", tab_line[0]);
	if (going == 0)
	{
		printf("command executed: %s\n", cmd);
		execve(cmd, tab_line, strc_env->env);
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


void		get_env(t_env *strc_env, char **env)
{
	int		j;

	j = 0;
	strc_env->env = env;
	strc_env->tab = (char***)ft_strnew(sizeof(char**) * 100);
	while (env[j] != NULL && j < 99)
	{
		printf("env[%d]: %s\n", j, env[j]);
		strc_env->tab[j] = ft_strsplit(env[j], '=');
		if (ft_strcmp(strc_env->tab[j][0], "PATH") == 0)
			strc_env->path = ft_strsplit(strc_env->tab[j][1], ':');
		if (ft_strcmp(strc_env->tab[j][0], "HOME") == 0)
			strc_env->home = strc_env->tab[j][1];
		if (ft_strcmp(strc_env->tab[j][0], "PWD") == 0)
			strc_env->pwd = strc_env->tab[j][1];
		if (ft_strcmp(strc_env->tab[j][0], "OLDPWD") == 0)
			strc_env->oldpwd = strc_env->tab[j][1];
		j++;
	}
	printf("\n");
	printf("\n");
	j = 0;
	while (strc_env->path[j] != NULL)
	{
		printf("strc_env->path[%d]: %s\n", j, strc_env->path[j]);
		j++;
	}
	printf("strc_env->pwd: %s\n", strc_env->pwd);
	printf("strc_env->oldpwd: %s\n", strc_env->oldpwd);
	printf("strc_env->home: %s\n", strc_env->home);
	printf("\n");
	printf("\n");
}


/*
   {
   pid_t	pid;
   int		status;
   char	*str;
   }
   pid = fork();
   if (pid > 0)
   {
   wait(&status);
   ft_putendl("processus fils termine: nous sommes dans le processus pere");
   }
   if (pid == 0)
   {
   str = ft_strdup("~/");
   execve("/bin/ls/", &str, env);
   free(str);
   }
   return (1);*/
