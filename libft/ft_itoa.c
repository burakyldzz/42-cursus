/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:40:20 by ayildiz           #+#    #+#             */
/*   Updated: 2024/10/29 19:12:11 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_char(int num)
{
	int	count;

	count = 0;
	if (num != 0)
	{
		if (num < 0)
		{
			num = num *(-1);
			count++;
		}
		while (num != 0)
		{
			num = num / 10;
			count++;
		}
	}
	else
		count = 1;
	return (count);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	nbr;

	len = count_char(n);
	nbr = n;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nbr)
	{
		str[len] = ((nbr % 10) + '0');
		nbr /= 10;
		len--;
	}
	return (str);
}
