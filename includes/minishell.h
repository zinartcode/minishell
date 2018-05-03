/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:40:47 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/02 20:56:15 by azinnatu         ###   ########.fr       */
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

void		process_args(char **env, char **envp);
char		**read_input(void);
void		format_str(char **line);
void		ft_cd(char **cmd, char **env);
char		*ft_cd_home(char **env);
char		**cd_env_change(char *cmd, char **env);
void		ft_cmd(char **cmd, char **env, char **envp);
char		*ft_findexec(char **paths, char *command);
char		**ft_getpath(char **envp);

void		create_env(char ***env, char **envp);
void		print_env(char **env);
void		free_env(char **env);

#endif