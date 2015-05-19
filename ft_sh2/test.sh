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
