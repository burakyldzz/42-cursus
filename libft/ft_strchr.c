/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:59:56 by ayildiz           #+#    #+#             */
/*   Updated: 2024/10/26 18:33:59 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	size_t	i;

	a = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == a)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (a == '\0')
		return ((char *)&s[i]);
	return (0);
}
