/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 21:08:33 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/01 17:25:35 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cmd(char **cmd, char **env, char **envp)
{
	char	*folder;
	pid_t	parent;
	char	*error;

	error = ft_strdup("ft_minishell1: command not found: ");
	if (cmd[0])
	{
		parent = fork();
		if (parent > 0)
			wait(0);
		else
		{
			if ((folder = ft_findexec(ft_getpath(envp), cmd[0])))
				execve(ft_strjoin(folder, cmd[0]), cmd, envp);
			else if (access(cmd[0], R_OK) == 0)
				execve(cmd[0], cmd, envp);
			else
				ft_putendl_fd(ft_strjoin(error, cmd[0]), 2);
			exit(0);
		}
	}
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