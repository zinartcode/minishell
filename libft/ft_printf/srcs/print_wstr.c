/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:55:22 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/29 21:21:11 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_wchar(t_printf *e, char c)
{
	e->ret += write(e->fd, &c, 1);
}

static void	put_wstr(t_printf *e, wchar_t c)
{
	if (c <= 0x7F)
		put_wchar(e, c);
	else if (c <= 0x7FF)
	{
		put_wchar(e, (c >> 6) + 0xC0);
		put_wchar(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		put_wchar(e, ((c >> 12) + 0xE0));
		put_wchar(e, ((c >> 6) & 0x3F) + 0x80);
		put_wchar(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		put_wchar(e, (c >> 18) + 0xF0);
		put_wchar(e, ((c >> 12) & 0x3F) + 0x80);
		put_wchar(e, ((c >> 6) & 0x3F) + 0x80);
		put_wchar(e, (c & 0x3F) + 0x80);
	}
}

static int	get_lenght(wchar_t *wc)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (wc[++i] != 0)
	{
		if (wc[i] <= 0x7F)
			len++;
		else if (wc[i] <= 0x7FF)
			len += 2;
		else if (wc[i] <= 0xFFFF)
			len += 3;
		else if (wc[i] <= 0x10FFFF)
			len += 4;
	}
	return (len);
}

static void	wstr_minus(t_printf *e, wchar_t *wc, int len)
{
	int	i;

	i = -1;
	if (e->flag.prec >= 0)
	{
		while (wc[++i] != 0 && i < e->flag.prec)
			put_wstr(e, wc[i]);
	}
	else
	{
		while (wc[++i] != 0)
			put_wstr(e, wc[i]);
	}
	while (e->flag.width-- > len)
		e->ret += (e->flag.zero == 1 ?
		write(e->fd, "0", 1) : write(e->fd, " ", 1));
}

void		print_wstr(t_printf *e, wchar_t *wc)
{
	int	i;
	int	len;

	i = -1;
	len = (e->flag.prec < 0 ? get_lenght(wc) : e->flag.prec);
	if (e->flag.minus)
		wstr_minus(e, wc, len);
	else
	{
		while (e->flag.width-- > len)
			e->ret += (e->flag.zero == 1 ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
		if (e->flag.prec >= 0)
			while (wc[++i] != 0 && i * 4 < e->flag.prec)
				put_wstr(e, wc[i]);
		else
			while (wc[++i] != 0)
				put_wstr(e, wc[i]);
	}
	e->i++;
}
