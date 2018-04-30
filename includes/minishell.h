/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:40:47 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/30 15:03:36 by azinnatu         ###   ########.fr       */
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
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define NRM "\x1B[0m"

char		**readinput(void);
void		replace(char **line);

void		print_env(char **env);

#endif