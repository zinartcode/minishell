/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:55:22 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/29 21:19:54 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_init(t_flag *flag)
{
	flag->sp = 0;
	flag->plus = 0;
	flag->neg = 0;
	flag->minus = 0;
	flag->hash = 0;
	flag->zero = 0;
	flag->prec = -1;
	flag->width = 0;
}

void	print_conversion(const char *restrict format, t_printf *e)
{
	e->i++;
	set_tag(format, e);
	set_flag(format, e);
	get_spec(format, e);
}

int		ft_printf(const char *restrict format, ...)
{
	t_printf	e;

	e.i = 0;
	e.ret = 0;
	e.fd = 1;
	va_start(e.ap[0], format);
	va_copy(e.ap[1], e.ap[0]);
	while (format[e.i] != '\0')
	{
		if (format[e.i] == '{')
			check_settings(format, &e);
		else if (format[e.i] == '%' && format[e.i + 1] != '%')
			print_conversion(format, &e);
		else if (format[e.i] == '%' && format[e.i + 1] == '%')
		{
			e.ret += write(e.fd, "%", 1);
			e.i += 2;
		}
		else
			e.ret += write(e.fd, &format[e.i++], 1);
	}
	va_end(e.ap[0]);
	return (e.ret);
}
