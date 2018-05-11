/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 21:08:33 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/10 20:26:52 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cmd(char **cmd, char **env)
{
	char	*temp;

	temp = (char*)ft_memalloc(PATH_MAX + 1);
	if (cmd[0])
	{
		if (cmd[0][0] == '$')
		{
			ft_strcpy(temp, &cmd[0][1]);
			ft_strclr(cmd[0]);
			ft_strcpy(cmd[0], temp);
			free(temp);
			ft_strcpy(cmd[0], find_exec_env(cmd, env));
		}
		ft_execute(cmd, env);
	}
	free(temp);
}

void	ft_execute(char **cmd, char **env)
{
	pid_t	parent;
	char	*folder;

	parent = fork();
	if (parent > 0)
		wait(0);
	else
	{
		if ((folder = ft_findexec(ft_getpath(env), cmd[0])))
			execve(ft_strjoin(folder, cmd[0]), cmd, env);
		else if (access(cmd[0], R_OK) == 0)
			execve(cmd[0], cmd, env);
		else
			ft_printf("ft_minishell1: command not found: ");
		exit(0);
	}
}

char	*find_exec_env(char **cmd, char **env)
{
	int		i;
	char	*temp;

	i = -1;
	temp = (char*)ft_memalloc(PATH_MAX + 1);
	ft_strcat(cmd[0], "=");
	while (env[++i])
	{
		if (!ft_strncmp(cmd[0], env[i], ft_strlen(cmd[0])))
			ft_strcpy(temp, ft_get_path(env, cmd[0]));
	}
	return (temp);
}

char	*ft_findexec(char **paths, char *command)
{
	if (command[0] != '.' && command[0] != '/' && command[0] != '~')
	{
		while (*paths)
		{
			if (access(ft_strjoin(*paths, command), R_OK) == 0)
				return (*paths);
			paths++;
		}
	}
	return (NULL);
}

char	**ft_getpath(char **env)
{
	char	**folders;
	int		i;

	while (*env)
	{
		if (ft_strstr(*env, "PATH="))
			break ;
		env++;
	}
	folders = ft_strsplit(ft_strstr(*env, "PATH=") + 5, ':');
	i = 0;
	while (folders[i])
	{
		folders[i] = ft_strjoin(folders[i], "/");
		i++;
	}
	return (folders);
}
