/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 20:17:30 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/01 23:53:13 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char **cmd, char **env)
{
	struct stat	statbuf;

	if (cmd[1] && stat(cmd[1], &statbuf))
		ft_putendl_fd(ft_strjoin("cd: No such file or directory: ",
			cmd[1]), 2);
	else if (!(S_ISDIR(statbuf.st_mode)) && cmd[1])
		ft_putendl_fd(ft_strjoin("cd: Not a directory: ",
			cmd[1]), 2);
	else if (access(cmd[1], X_OK) == -1 && cmd[1])
		ft_putendl_fd(ft_strjoin("cd: Permission Denied: ", cmd[1]), 2);
	else if (cmd[1] == 0)
		chdir(ft_cd_home(env));
	else
	{
		env = cd_env_change(cmd, env);
		chdir(cmd[1]);
	}
}

char	*ft_cd_home(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strstr("HOME=", envp[i]) == 0)
			return (envp[i + 3] + 5);
		i++;
	}
	return NULL;
}

char	**cd_env_change(char **cmd, char **env)
{
	int		i;
	// int		len;
	char	*temp;
	char	*old;

	i = -1;
	old = (char*)ft_memalloc(PATH_MAX + 1);
	old = ft_strdup("OLD");
	// len = ft_strlen(cmd[1])
	temp = (char*)ft_memalloc(PATH_MAX + 1);
	// change PWD
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PWD", 3))
			break ;
	}
	temp = ft_strdup(env[i]);
	ft_strcat(env[i], "/");
	ft_strcat(env[i], cmd[1]);
	ft_printf("%s\n", env[i]); //test

	// change OLDPWD
	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "OLDPWD",6))
			break ;
	}
	ft_strclr(env[i]);
	ft_strcat(old, temp);
	env[i] = ft_strdup(old);
	ft_printf("%s\n", env[i]);
	free(old);
	free(temp);
	return (env);
}