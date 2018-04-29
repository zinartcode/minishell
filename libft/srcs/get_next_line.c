/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 14:37:08 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/02 14:59:09 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_realloc(char **str)
{
	char *tmp;

	if (str)
	{
		tmp = ft_strnew(ft_strlen(*str));
		ft_strcpy(tmp, *str);
		ft_memdel((void **)str);
		*str = ft_strnew(ft_strlen(tmp) + BUFF_SIZE);
		ft_strcpy(*str, tmp);
		free(tmp);
	}
}

void	find_n(char **line, char **buff, int bytes)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while ((*line)[++i])
	{
		if ((*line)[i] == '\n')
			(*line)[i] = '\0';
	}
	i = -1;
	if (bytes < BUFF_SIZE)
		(*buff)[bytes] = 0;
	while (++i < BUFF_SIZE)
	{
		if ((*buff)[i] == '\n')
		{
			while (++i < BUFF_SIZE)
				(*buff)[j++] = (*buff)[i];
		}
	}
	while (j < BUFF_SIZE)
		(*buff)[j++] = 0;
}

int		obhod_norminett(char **buff, char **line)
{
	ft_strcpy(*line, *buff);
	if (ft_memchr(*buff, '\n', BUFF_SIZE))
	{
		find_n(line, buff, BUFF_SIZE);
		(ft_strlen(*buff) == 0) ? ft_memdel((void **)buff) : 0;
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buff;
	int			bytes;

	if (fd < 0 || read(fd, buff, 0) || !line)
		return (-1);
	if (!(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (buff)
	{
		if (obhod_norminett(&buff, line) == 1)
			return (1);
		free(buff);
	}
	buff = ft_strnew(BUFF_SIZE);
	while ((bytes = read(fd, buff, BUFF_SIZE)))
	{
		ft_realloc(line);
		ft_strncat(*line, buff, bytes);
		if (ft_memchr(buff, '\n', bytes))
			break ;
	}
	find_n(line, &buff, bytes);
	if (bytes == 0 && ft_strlen(*line) == 0)
		return (0);
	return (1);
}
