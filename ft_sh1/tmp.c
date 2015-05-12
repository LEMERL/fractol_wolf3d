#include "sh1.h"



#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>

/*
	char	*futur_old;
		futur_old = getcwd(NULL, 0);
			&& chdir(dir) == 0)
			change_pwd_old(futur_old);
		ft_strdel(&futur_old);
			*/

int		file_dir_link(struct stat s, char *path);

static int	try_access(struct stat s, char *path)
{
	int		ret;

	ret = 0;
	if (access(path, F_OK) == 0)
	{
		if (access(path, X_OK) == 0)
			ret = file_dir_link(s, path);
		else
			ft_putstr("permission denied: ");
	}
	else
		ft_putstr("no such file or directory: ");
	ft_putendl(path);
	return (ret);
}

int		file_dir_link(struct stat s, char *path)
{
	int		ret;
	char	*tmp;
	int		len;

	ret = 0;
	if (S_ISDIR(s.st_mode) != 0)
		ret = 2;
	else if(S_ISREG(s.st_mode) != 0)
		ret = 1;
	else if (S_ISLNK(s.st_mode))
	{
		tmp = ft_strnew(1024);
		if ((len = readlink(path, tmp, 1023)) == -1)
			exit (-1);//error();
		tmp[len] = '\0';
		ft_putendl("gestion of the symlinks has not been implented yet");
		ft_putstr(path);
		ft_putstr(" redirect to ");
		ft_putendl(tmp);
		ft_strdel(&tmp);
		ret = 3;
	}
	return (ret);
}

int		check_file(char *path)
{
	struct stat	s;
	char		*f;
	char		*pwd;
	int			ret;

	if (*path != '/')
	{
		f = ft_strnew(ft_strlen(path) + ft_strlen((pwd = getcwd(NULL, 0))) + 2);
		f = ft_strcat(ft_strcat(ft_strcpy(f, pwd), "/"), path);
		ft_memdel((void**)&pwd);
	}
	else
		f = ft_strdup(path);
	ret = 0;
	if(stat(f, &s) == 0)
		ret = try_access(s, f);
	ft_memdel((void**)&f);
	return (ret);
}
