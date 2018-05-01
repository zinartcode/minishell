/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 20:17:30 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/30 20:45:41 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char **cmd, char **envp)
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
		chdir(ft_cd_home(envp));
	else
		chdir(cmd[1]);
}

char	*ft_cd_home(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strstr("HOME=", envp[i]) == 0)
			return (envp[i]);
		i++;
	}
	return NULL;
}