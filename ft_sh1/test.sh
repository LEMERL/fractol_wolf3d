cd .
echo $PWD
echo $OLDPWD
cd ~/Desktop 
echo $PWD
echo $OLDPWD
ls -la
cd -
echo $PWD
echo $OLDPWD
unsetenv PWD OLDPWD USER
echo $SHLVL
env -i /nfs/zfs-student-2/users/2014/mgrimald/git_perso/fractol_wolf3d/ft_sh1/ft_minishell1
echo $SHLVL
leaks ft_minishell1
exit
