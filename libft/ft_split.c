/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:09:45 by ayildiz           #+#    #+#             */
/*   Updated: 2024/11/10 19:27:25 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_wordcounter(char const *s, char c)
{
	int	ct;

	ct = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			++ct;
		while (*s != c && *s)
			++s;
	}
	return (ct);
}

static	char	**ft_free_all(char **rt)
{
	int	i;

	i = 0;
	while (rt[i])
	{
		free(rt[i]);
		i++;
	}
	free(rt);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**rt;
	int		j;
	int		k;

	rt = malloc (sizeof (char *) * (ft_wordcounter(s, c) + 1));
	if (!rt || !s)
		return (NULL);
	k = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
		{
			j = 0;
			while (s[j] && s[j] != c)
				j++;
			rt[k] = ft_substr(s, 0, j);
			if (rt[k++] == NULL)
				return (ft_free_all(rt));
			s += j;
		}
	}
	rt[k] = NULL;
	return (rt);
}
