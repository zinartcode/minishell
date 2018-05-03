/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 20:17:30 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/02 21:16:33 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char **cmd, char **env)
{
	struct stat	statbuf;

	if (cmd[1] == 0 || ft_strcmp(cmd[1], "~") == 0)
	{
		env = cd_env_change("..", env);
		chdir(ft_cd_home(env));
	}
	else if (cmd[1] && stat(cmd[1], &statbuf))
		ft_putendl_fd(ft_strjoin("cd: No such file or directory: ",
			cmd[1]), 2);
	else if (!(S_ISDIR(statbuf.st_mode)) && cmd[1])
		ft_putendl_fd(ft_strjoin("cd: Not a directory: ",
			cmd[1]), 2);
	else if (access(cmd[1], X_OK) == -1 && cmd[1])
		ft_putendl_fd(ft_strjoin("cd: Permission Denied: ", cmd[1]), 2);
	else if (cmd[2] != 0)
		ft_putendl_fd("cd: Too many arguments.", 2);
	else
	{
		env = cd_env_change(cmd[1], env);
		chdir(cmd[1]);
	}
}

char	*ft_cd_home(char **env)
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
			ft_strclr(home);
			home = ft_strcpy(home, &env[i][5]);
			while (env[j] && ft_strncmp(env[j], "PWD", 3))
				j++;
			ft_strclr(env[j]);
			env[j] = ft_strcpy(env[j], "PWD=");
			// ft_printf("home is %s\n", env[j]);
			ft_strcat(env[j], home);
			// ft_printf("home is %s\n", env[j]);
			free(home);
			return (&env[i][5]);
		}
		i++;
	}
	return NULL;
}

char	**cd_env_change(char *cmd, char **env)
{
	int		i;
	// int		len;
	char	*temp;
	char	*old;

	i = -1;
	old = (char*)malloc(PATH_MAX + 1);
	old = ft_strcpy(old, "OLD");
	temp = (char*)malloc(PATH_MAX + 1);
	// change PWD
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PWD", 3))
			break ;
	}
	temp = ft_strcpy(temp, env[i]);
	if (ft_strcmp(cmd, "..") != 0)
	{
		ft_strcat(env[i], "/");
		ft_strcat(env[i], cmd);
		// ft_printf("%s\n", env[i]); //test
	}

	// change OLDPWD
	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "OLDPWD",6))
			break ;
	}
	ft_strclr(env[i]);
	ft_strcat(old, temp);
	ft_strcpy(env[i], old);
	// ft_printf("%s\n", env[i]);  //test
	free(old);
	free(temp);
	return (env);
	//fix cd ..
}