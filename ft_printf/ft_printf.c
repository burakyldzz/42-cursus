/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:33:46 by ayildiz           #+#    #+#             */
/*   Updated: 2024/12/22 16:36:19 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(int c, va_list arg)
{
	size_t	s;

	s = 0;
	if (c == 'c')
		s += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		s += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		s += ft_putnbr(va_arg(arg, int), 10, "0123456789");
	else if (c == 'u')
		s += ft_putnbr(va_arg(arg, unsigned int), 10, "0123456789");
	else if (c == 'X')
		s += ft_putnbr(va_arg(arg, unsigned int), 16, "0123456789ABCDEF");
	else if (c == 'x')
		s += ft_putnbr(va_arg(arg, unsigned int), 16, "0123456789abcdef");
	else if (c == 'p')
		s += ft_ptrnbr(va_arg(arg, size_t), 16, "0123456789abcdef");
	else if (c == '%')
		s += ft_putchar('%');
	return (s);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	s;
	va_list	arg;

	i = 0;
	s = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
			s += ft_control(format[++i], arg);
		else
			s += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (s);
}
