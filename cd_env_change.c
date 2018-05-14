/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_env_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:03:09 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/10 19:57:36 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**cd_env_change(char *cmd, char **env, int i)
{
	char	*temp;

	temp = (char*)malloc(PATH_MAX + 1);
	while (env[++i])
		if (!ft_strncmp(env[i], "PWD=", 4))
			break ;
	temp = ft_strcpy(temp, env[i]);
	if (cmd[0] == '/')
	{
		ft_strclr(env[i]);
		env[i] = ft_strcpy(env[i], "PWD=");
		ft_strcat(env[i], cmd);
	}
	else if (cmd[0] == '.')
		env = cd_env_back(cmd, env, i);
	else if (!ft_strncmp(&cmd[0], ft_get_path(env, "HOME="), 7))
		ft_strcpy(env[i], &cmd[0]);
	else
	{
		ft_strcat(env[i], "/");
		ft_strcat(env[i], cmd);
	}
	env = cd_env_change_2(temp, env);
	free(temp);
	return (env);
}

char		**cd_env_change_2(char *temp, char **env)
{
	int		i;
	char	*old;

	old = (char*)malloc(PATH_MAX + 1);
	old = ft_strcpy(old, "OLD");
	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "OLDPWD=", 7))
			break ;
	}
	ft_strclr(env[i]);
	ft_strcat(old, temp);
	ft_strcpy(env[i], old);
	free(old);
	return (env);
}

char		**cd_env_old(char **env, int i)
{
	char	*old;
	char	*curr;

	old = (char*)ft_memalloc(PATH_MAX + 1);
	curr = (char*)ft_memalloc(PATH_MAX + 1);
	ft_strcpy(old, ft_get_path(env, "OLDPWD="));
	ft_strcpy(curr, ft_get_path(env, "PWD="));
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "OLDPWD=", 7))
		{
			ft_strclr(&env[i][7]);
			ft_strcat(env[i], curr);
		}
		if (!ft_strncmp(env[i], "PWD=", 4))
		{
			ft_strclr(&env[i][4]);
			ft_strcat(env[i], old);
		}
	}
	chdir(old);
	free(old);
	free(curr);
	return (env);
}

char		*ft_cd_home(char **cmd, char **env, int flag)
{
	int		i;
	int		j;
	char	*home;

	i = 0;
	j = 0;
	home = (char*)ft_memalloc(PATH_MAX + 1);
	while (env[i])
	{
		if (!ft_strncmp(env[i], "HOME", 4))
		{
			home = ft_strcpy(home, &env[i][5]);
			while (env[j] && ft_strncmp(env[j], "PWD", 3))
				j++;
			ft_strclr(env[j]);
			env[j] = ft_strcpy(env[j], "PWD=");
			ft_strcat(env[j], home);
			if (flag == 1)
				ft_strcat(env[j], &cmd[1][1]);
			free(home);
			return (&env[i][5]);
		}
		i++;
	}
	return (NULL);
}

char		**cd_env_back(char *cmd, char **env, int i)
{
	char	*pth;
	int		j;

	pth = (char*)malloc(PATH_MAX + 1);
	if (ft_strncmp(cmd, "..", 2) == 0)
	{
		j = ft_strlen(env[i]);
		while (env[i][--j] != '/')
			env[i][j] = 0;
		env[i][j] = 0;
		if (cmd[3] != 0 || cmd[3] != '\0')
		{
			pth = ft_strcpy(pth, &cmd[3]);
			env = cd_env_change(pth, env, -1);
		}
	}
	free(pth);
	return (env);
}
