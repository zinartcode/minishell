/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 21:08:33 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/10 15:11:36 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cmd(char **cmd, char **env)
{
	char	*folder;
	pid_t	parent;
	char	*error;
	char	*temp;

	error = ft_strdup("ft_minishell1: command not found: ");
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
				ft_putendl_fd(ft_strjoin(error, cmd[0]), 2);
			exit(0);
		}
	}
	free(error);
	free(temp);
}

char	*find_exec_env(char **cmd, char **env)
{
	int		i;
	char	*temp;

	i = -1;
	temp = (char*)ft_memalloc(PATH_MAX + 1);
	ft_strcat(cmd[0], "=");
	while(env[++i])
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
	return NULL;
}

char	**ft_getpath(char **envp)
{
	char	**folders;
	int		i;

	while (*envp)
	{
		if (ft_strstr(*envp, "PATH="))
			break ;
		envp++;
	}
	folders = ft_strsplit(ft_strstr(*envp, "PATH=") + 5, ':');
	i = 0;
	while (folders[i])
	{
		folders[i] = ft_strjoin(folders[i], "/");
		i++;
	}
	return (folders);
}