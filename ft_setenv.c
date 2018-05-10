/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 00:55:03 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/09 00:55:53 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_setenv(char **cmd, char **env)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	if (i == 1)
		return (env);
	else if (i == 2)
		env = set_name(cmd, env);
	else if (i == 3)
		env = set_full(cmd, env);
	else
		ft_printf("setenv: Too many arguments.\n");
	return (env);
}

char	**set_name(char **cmd, char **env)
{
	char	***new;
	char	**envp;
	int		i;

	i = -1;
	new = &env;
	while ((*new)[++i])
		NULL;
	envp = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	i = -1;
	while ((*new)[++i])
		envp[i] = ft_strdup((*new)[i]);
	free_env(env);
	envp[i] = (char*)ft_memalloc(PATH_MAX + 1);
	ft_strncat(envp[i], cmd[1], ft_strlen(cmd[1]));
	ft_strncat(envp[i], "=", 1);
	new = &envp;
	return (*new);
}

char	**set_full(char **cmd, char **env)
{
	int	i;
	int	flag;

	flag = 0;
	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(cmd[1], env[i], ft_strlen(cmd[1])))
		{
			flag = 1;
			env = modify_env(cmd, env, i);
			return (env);
		}
	}
	if (flag == 0)
		env = set_name(cmd, env);
	ft_strncat(env[i], cmd[2], ft_strlen(cmd[2]));
	return (env);
}

char	**modify_env(char **cmd, char **env, int i)
{
	int	j;

	ft_strcat(cmd[1], "=");
	j = ft_strlen(cmd[1]);
	if (!ft_strncmp(cmd[1], env[i], j))
	{
		ft_strclr(&env[i][j]);
		ft_strcat(env[i], cmd[2]);
	}
	return (env);
}
