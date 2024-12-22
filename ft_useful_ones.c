/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useful_ones.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:43:56 by ayildiz           #+#    #+#             */
/*   Updated: 2024/12/22 10:09:54 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	size_t	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long i, int base, char *range)
{
	size_t	s;

	s = 0;
	if (i < 0)
	{
		s += ft_putchar('-');
		i *= -1;
	}
	if (i < base)
		s += ft_putchar(range[i]);
	else
	{
		s += ft_putnbr((i / base), base, range);
		s += ft_putnbr((i % base), base, range);
	}
	return (s);
}

int	ft_ptrnbr(long i, int base, char *range)
{
	size_t	s;

	s = 0;
	if (i == 0)
	{
		s += write(1, "(nil)", 5);
		return (s);
	}
	ft_putchar('0');
	ft_putchar('x');
	s = 2;
	if (i < base)
		s += ft_putchar(range[i]);
	else
	{
		s += ft_putnbr((i / base), base, range);
		s += ft_putnbr((i % base), base, range);
	}
	return (s);
}
