# ft_sh1
execution of any given file [./|../|path/to/exec|/full/path/to/exec|exec_in_the_path]
cd [ |.|..|dir|/path/to/dir]
env: print the environment variables
env cmd arg: execute the command with a given environment
env -i cmd arg: execute the command in an empty environment
setenv _HEAD body
unsetenv HEAD_1 HEAD_2 HEAD_3 ...
exit [0-255]
gestion of '~' and $VAR_ENV in the command line
gestion of quote " ' " and ' " '. (Automatically claused by a LF [10])
gestion of inhibitor '\'. (Does not apply on LF [10])
Automatically execute a file given in argument.(each command separated by a new line)
Possibility to set a personnalised prompt by setting PROMPT_MESS with the wanted element.
(PROMPT_MESS can be set with other env variables and colors but it needs to be properly formated. (inhibitors help a lot))
basic interception and inhibition of a few signal (^Z and ^C)

if you find any crash or leaks, please report them to mgrimald@student.42.fr

ENJOY :-D
