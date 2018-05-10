/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 19:46:44 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/09 21:58:11 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_echo(char **cmd, char **env)
{
	int	i;
	int	new_line;

	i = 0;
	new_line = 0;
	while (cmd[i])
		i++;
	if (i == 1)
		ft_printf("\n");
	else if (i == 2)
	{
		if (cmd[1][0] == '$')
			echo_env(cmd[1], env);
		else
			ft_printf("%s\n", cmd[1]);
	}
	else
		process_echo(cmd, env, i, new_line);
}

void	process_echo(char **cmd, char **env, int i, int new_line)
{
	int	n;

	n = 1;
	if (new_line == 1)
		n++;
	while (cmd[n])
	{
		if (cmd[n][0] == '$')
			echo_env(cmd[n], env);
		else
			ft_printf("%s ", cmd[n]);
		n++;
	}
	ft_printf("\n");
}

void	echo_env(char *cmd, char **env)
{
	int	i;
	char	*temp;

	i = -1;
	temp = (char*)ft_memalloc(PATH_MAX + 1);
	ft_strcpy(temp, &cmd[1]);
	ft_strcat(temp, "=");
	while (env[++i])
	{
		if (!ft_strncmp(temp, env[i], ft_strlen(temp)))
			ft_printf("%s ", ft_get_path(env, temp));
	}
	free(temp);
}
