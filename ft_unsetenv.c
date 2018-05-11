/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:26:24 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/10 19:58:21 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_unsetenv(char **cmd, char **env)
{
	int	i;
	int	j;

	i = -1;
	while (cmd[++i])
	{
		j = -1;
		ft_strcat(cmd[i], "=");
		while (env[++j])
		{
			if (!ft_strncmp(cmd[i], env[j], ft_strlen(cmd[i])))
				break ;
		}
		free(env[j]);
		j--;
		while (env[++j])
			env[j] = env[j + 1];
		env[j] = NULL;
	}
	return (env);
}
