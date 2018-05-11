/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 20:17:30 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/10 19:55:24 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_cd(char **cmd, char **env, char *temp)
{
	if (cmd[1] == 0 || ft_strcmp(cmd[1], "~") == 0 ||
		ft_strcmp(cmd[1], "~/") == 0)
	{
		env = cd_env_change("", env, -1);
		chdir(ft_cd_home(cmd, env, 0));
	}
	else if (cmd[1] && ft_strcmp(cmd[1], "-") == 0)
		cd_env_old(env, -1);
	else if (ft_strncmp(cmd[1], "~/", 2) == 0 && cmd[1][2] != 0)
	{
		if (check_dir(cmd) != 1)
		{
			ft_strcpy(temp, ft_get_path(env, "HOME"));
			ft_strcat(temp, &cmd[1][1]);
			ft_strclr(cmd[1]);
			ft_strcpy(cmd[1], temp);
		}
	}
	else if (check_dir(cmd) != 1)
	{
		env = cd_env_change(cmd[1], env, -1);
		chdir(cmd[1]);
	}
}

int			check_dir(char **cmd)
{
	struct stat	statbuf;

	if (cmd[2] != 0)
	{
		ft_printf("cd: Too many arguments.\n");
		return (1);
	}
	else if (access(cmd[1], X_OK) == -1 && cmd[1])
	{
		ft_printf("%s: Could not change directory\n", cmd[1]);
		return (1);
	}
	else if (cmd[1] && stat(cmd[1], &statbuf))
	{
		ft_printf("%s: no such file or directory\n", cmd[1]);
		return (1);
	}
	else if (!(S_ISDIR(statbuf.st_mode)) && cmd[1])
	{
		ft_printf("%s: Could not change directory\n", cmd[1]);
		return (1);
	}
	return (0);
}

char		*ft_get_path(char **env, char *name)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(name);
	while (env[i])
	{
		if (!ft_strncmp(env[i], name, j))
			return (&env[i][j++]);
		i++;
	}
	return (NULL);
}
