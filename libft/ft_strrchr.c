/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:52:40 by ayildiz           #+#    #+#             */
/*   Updated: 2024/11/09 17:17:58 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	char_c;
	int		i;

	char_c = (char) c;
	i = ft_strlen(s);
	s += i;
	while (i >= 0)
	{
		if (*s == char_c)
			return ((char *)s);
		i--;
		s--;
	}
	return (NULL);
}
