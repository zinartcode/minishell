/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:46:30 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/09 02:17:46 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **cmd, char **env)
{
	int	i;
	int	len;
	int	flag;

	i = -1;
	flag = 0;
	len = 0;
	while (cmd[len])
		len++;
	if (len >= 3)
		ft_printf("Too many arguments\n");
	else if (len == 2)
	{
		cmd[1] = ft_strjoin(cmd[1], "=");
		len = ft_strlen(cmd[1]);
		while (env[++i])
		{
			if (!ft_strncmp(cmd[1], env[i], len))
			{
				flag = 1;
				ft_printf("%s\n", &env[i][len + 1]);
			}
		}
		if (flag == 0)
			ft_printf("%s: No such file or directory\n", cmd[1]);
	}
	else
		print_env(env);
}

void	create_env(char ***env, char **envp)
{
	int i;
	int j;

	i = -1;
	while (envp[++i])
		NULL;
	(*env) = (char**)ft_memalloc(sizeof(char*) * i);
	i = -1;
	while (envp[++i])
	{
		(*env)[i] = (char*)ft_memalloc(PATH_MAX + 1);
		j = -1;
		while (envp[i][++j])
			(*env)[i][j] = envp[i][j];
		(*env)[i][j] = 0;
	}
	(*env)[i] = NULL;
}

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_printf("%s\n", env[i]);
		i++;
	}
}

void	free_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}