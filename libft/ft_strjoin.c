/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:32:49 by ayildiz           #+#    #+#             */
/*   Updated: 2024/10/28 18:22:16 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*result;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1len + 1);
	ft_strlcpy(result + s1len, s2, s2len + 1);
	result[s1len + s2len] = '\0';
	return (result);
}
