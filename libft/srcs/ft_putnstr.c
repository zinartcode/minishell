/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 21:44:55 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/10 22:29:09 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_putnstr(char const *s, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		write(1, &s[i], 1);
	return (i);
}
