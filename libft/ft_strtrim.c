/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:38:58 by ayildiz           #+#    #+#             */
/*   Updated: 2024/11/10 16:23:44 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_checker(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (ft_set_checker(*s1, set) == 1)
			s1++;
		else
			break ;
	}
	size = ft_strlen(s1);
	while (size)
	{
		if (ft_set_checker(s1[size - 1], set) == 1)
			size--;
		else
			break ;
	}
	str = (char *)malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, size + 1);
	return (str);
}
