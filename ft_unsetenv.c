/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:26:24 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/09 18:30:43 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_unsetenv(char **cmd, char **env)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	ft_printf("%d\n", i);
	return (env);
}