/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:40:47 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/10 20:26:53 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/includes/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <stdio.h>
# define SIZE 40
# define BOLD	"\e[1m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define NRM "\x1B[0m"

void		process_args(char **cmd, char **env, char **envp, char *temp);
void		format_str(char **line);
void		ft_cd(char **cmd, char **env, char *temp);
void		ft_env(char **cmd, char **env, int len, int i);
void		ft_echo(char **cmd, char **env);
void		ft_cmd(char **cmd, char **env, char **envp);
void		ft_execute(char *temp, char **cmd, char **env, char **envp);
void		echo_env(char *cmd, char **env);
void		process_echo(char **cmd, char **env, int new_line);
int			check_dir(char **cmd);
char		**read_input(void);
char		**ft_getpath(char **env);
char		*ft_get_path(char **env, char *name);
char		*ft_cd_home(char **cmd, char **env, int flag);
char		**cd_env_change(char *cmd, char **env, int i);
char		**cd_env_change_2(char *temp, char **env);
char		**cd_env_back(char *cmd, char **env, int i);
char		**cd_env_old(char **env, int i);
char		*ft_findexec(char **paths, char *command);
char		*find_exec_env(char *path, char **env);

void		create_env(char ***env, char **envp);
void		print_env(char **env);
void		free_env(char **env);
char		**ft_setenv(char **cmd, char **env);
char		**ft_unsetenv(char **cmd, char **env);
char		**modify_env(char **cmd, char **env, int i);
char		**set_name(char **cmd, char **env);
char		**set_full(char **cmd, char **env);

#endif
