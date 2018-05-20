# minishell

A 42 Silicon Valley project to create a Unix-like shell in c


## Installation and Running

Step 1: Clone the repository

```
git clone https://github.com/zinartcode/minishell.git minishell
```

Step 2: cd into the repo directory and run 'make':

```
cd minishell && make
```

Step 3: run the executable:

```
./minishell
```
## Allowed functions:

◦ opendir ◦ readdir ◦ closedir ◦ malloc

◦ getcwd ◦ chdir ◦ fork

◦ stat ◦ lstat ◦ fstat

◦ open ◦ close ◦ exit

◦ read ◦ write ◦ free

◦ execve ◦ access 

◦ wait ◦ waitpid ◦ wait3 ◦ wait4

◦ signal ◦ kill
## Commands

The minishell can run any system executables located in the PATH environmental variable, as well as some simple builtins.

### Builtin Commands

Builtin commands include:

To exit the minishell:
```
exit
```

Displaying environmental variables using 'env':
```
env
```

Setting evironmental variables using 'setenv':
```
setenv FOO BAR
```

Un-setting evironmental variables using 'unsetenv':
```
unsetenv FOO
```

Echoing text to the standard output using 'echo':
```
echo Hey  $USER "what is the meaning of life?"
```

Changing the working directory using 'cd':
```
cd ~/Desktop
```


## Authors

Artur Zinatullin

