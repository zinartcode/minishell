/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 21:08:33 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/11 15:33:36 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cmd(char **cmd, char **env, char **envp)
{
	char	*temp;

	temp = (char*)ft_memalloc(PATH_MAX + 1);
	if (cmd[0])
	{
		if (cmd[0][0] == '$')
		{
			ft_strcpy(temp, &cmd[0][1]);
			ft_strcpy(temp, find_exec_env(temp, env));
		}
		else
			ft_strcpy(temp, cmd[0]);
		ft_execute(temp, cmd, env, envp);
	}
	free(temp);
}

void	ft_execute(char *temp, char **cmd, char **env, char **envp)
{
	pid_t	parent;
	char	*folder;

	parent = fork();
	if (parent > 0)
		wait(0);
	else if (access(temp, F_OK) != -1)
		execve(temp, cmd, envp);
	else
	{
		if ((folder = ft_findexec(ft_getpath(env), temp)))
			execve(ft_strjoin(folder, temp), cmd, env);
		else if (access(temp, R_OK) == 0)
			execve(temp, cmd, envp);
		else
			ft_printf("%s: command not found\n", cmd[0]);
		exit(0);
	}
}

char	*find_exec_env(char *path, char **env)
{
	int		i;
	char	*temp;

	i = -1;
	temp = (char*)ft_memalloc(PATH_MAX + 1);
	ft_strcat(path, "=");
	while (env[++i])
	{
		if (!ft_strncmp(path, env[i], ft_strlen(path)))
			ft_strcpy(temp, ft_get_path(env, path));
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
