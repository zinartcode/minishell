/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:55:22 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/29 21:20:37 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	set font format: bright, dim underlined, blink, reverce, hidden,
**	reset bright, reset dim, reset underlined, reset blink, reset reverse.
*/

void	set_format(const char *restrict format, t_printf *e)
{
	if (!ft_strncmp(format + e->i, "{SET:RB}", 8))
		e->ret += write(e->fd, "\x1B[1m", 4);
	else if (!ft_strncmp(format + e->i, "{SET:DM}", 8))
		e->ret += write(e->fd, "\x1B[2m", 4);
	else if (!ft_strncmp(format + e->i, "{SET:UL}", 8))
		e->ret += write(e->fd, "\x1B[4m", 4);
	else if (!ft_strncmp(format + e->i, "{SET:BL}\0", 9))
		e->ret += write(e->fd, "\x1B[5m", 4);
	else if (!ft_strncmp(format + e->i, "{SET:RV}", 8))
		e->ret += write(e->fd, "\x1B[7m", 4);
	else if (!ft_strncmp(format + e->i, "{SET:HD}", 8))
		e->ret += write(e->fd, "\x1B[8m", 4);
	else if (!ft_strncmp(format + e->i, "{SET:RB}", 8))
		e->ret += write(e->fd, "\x1B[21m", 5);
	else if (!ft_strncmp(format + e->i, "{SET:RD}", 8))
		e->ret += write(e->fd, "\x1B[22m", 5);
	else if (!ft_strncmp(format + e->i, "{SET:RU}", 8))
		e->ret += write(e->fd, "\x1B[24m", 5);
	else if (!ft_strncmp(format + e->i, "{SET:RB}", 8))
		e->ret += write(e->fd, "\x1B[25m", 5);
	else if (!ft_strncmp(format + e->i, "{SET:RR}", 8))
		e->ret += write(e->fd, "\x1B[27m", 5);
	else
		return ;
	e->i += 8;
}

/*
**	set text color: default, black, red, green, yellow, blue, dark grey,
**	light red, light green, light eyllow, light blue.
*/

void	set_text_color(const char *restrict format, t_printf *e)
{
	if (!ft_strncmp(format + e->i, "{STC:DF}", 8))
		e->ret += write(e->fd, "\x1B[39m", 5);
	else if (!ft_strncmp(format + e->i, "{STC:BL}", 8))
		e->ret += write(e->fd, "\x1B[30m", 5);
	else if (!ft_strncmp(format + e->i, "{STC:RD}", 8))
		e->ret += write(e->fd, "\x1B[31m", 5);
	else if (!ft_strncmp(format + e->i, "{STC:GR}", 8))
		e->ret += write(e->fd, "\x1B[32m", 5);
	else if (!ft_strncmp(format + e->i, "{STC:YL}", 8))
		e->ret += write(e->fd, "\x1B[33m", 5);
	else if (!ft_strncmp(format + e->i, "{STC:BL}", 8))
		e->ret += write(e->fd, "\x1B[34m", 5);
	else if (!ft_strncmp(format + e->i, "{STC:DG}", 8))
		e->ret += write(e->fd, "\x1B[90m", 5);
	else if (!ft_strncmp(format + e->i, "{STC:LR}", 8))
		e->ret += write(e->fd, "\x1B[91m", 5);
	else if (!ft_strncmp(format + e->i, "{STC:LG}", 8))
		e->ret += write(e->fd, "\x1B[92m", 5);
	else if (!ft_strncmp(format + e->i, "{STC:LY}", 8))
		e->ret += write(e->fd, "\x1B[93m", 5);
	else if (!ft_strncmp(format + e->i, "{STC:LB}", 8))
		e->ret += write(e->fd, "\x1B[94m", 5);
	else
		return ;
	e->i += 8;
}

/*
**	set background color default, black, red, green, yellow, blue,
**	dark grey, light red, light green, light yellow, light blue.
*/

void	set_bg_color(const char *restrict format, t_printf *e)
{
	if (!ft_strncmp(format + e->i, "{SBC:DF}", 8))
		e->ret += write(e->fd, "\x1B[49m", 5);
	else if (!ft_strncmp(format + e->i, "{SBC:BK}", 8))
		e->ret += write(e->fd, "\x1B[40m", 5);
	else if (!ft_strncmp(format + e->i, "{SBC:RD}", 8))
		e->ret += write(e->fd, "\x1B[41m", 5);
	else if (!ft_strncmp(format + e->i, "{SBC:GR}", 8))
		e->ret += write(e->fd, "\x1B[42m", 5);
	else if (!ft_strncmp(format + e->i, "{SBC:YL}", 8))
		e->ret += write(e->fd, "\x1B[43m", 5);
	else if (!ft_strncmp(format + e->i, "{SBC:BL}", 8))
		e->ret += write(e->fd, "\x1B[44m", 5);
	else if (!ft_strncmp(format + e->i, "{SBC:DG}", 8))
		e->ret += write(e->fd, "\x1B[100m", 6);
	else if (!ft_strncmp(format + e->i, "{SBC:LR}", 8))
		e->ret += write(e->fd, "\x1B[101m", 6);
	else if (!ft_strncmp(format + e->i, "{SBC:LG}", 8))
		e->ret += write(e->fd, "\x1B[102m", 6);
	else if (!ft_strncmp(format + e->i, "{SBC:LY}", 8))
		e->ret += write(e->fd, "\x1B[103m", 6);
	else if (!ft_strncmp(format + e->i, "{SBC:LB}", 8))
		e->ret += write(e->fd, "\x1B[104m", 6);
	else
		return ;
	e->i += 8;
}

void	check_settings(const char *restrict format, t_printf *e)
{
	int	tmp;

	tmp = e->i;
	if (!ft_strncmp(format + e->i, "{OFF}", 5))
	{
		e->ret += write(e->fd, "\x1B[0m", 4);
		e->i += 5;
		return ;
	}
	else if (!ft_strncmp(format + e->i, "{SET:", 5))
		set_format(format, e);
	else if (!ft_strncmp(format + e->i, "{STC:", 5))
		set_text_color(format, e);
	else
		set_bg_color(format, e);
	if (tmp == e->i)
		e->ret += write(e->fd, &format[e->i++], 1);
}
