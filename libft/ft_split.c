/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:09:45 by ayildiz           #+#    #+#             */
/*   Updated: 2024/10/29 18:18:44 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_wordcounter(char const *s, char c)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			ct++;
		while (s[i] != c && s[i])
			i++;
	}
	return (ct);
}

static	char	**ft_splitter(char const *s, char c, char **rt)
{
	int	i;
	int	j;
	int	templen;

	i = 0;
	j = -1;
	while (s[i])
	{
		templen = 0;
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			j++;
		while (s[i + templen] != c && s[i + templen])
			templen++;
		if (templen > 0)
			rt[j] = ft_substr(s, i, templen);
		i += templen;
	}
	rt[++j] = '\0';
	return (rt);
}

char	**ft_split(char const *s, char c)
{
	char	**rt;

	if (!s)
		return (0);
	rt = malloc (sizeof (char *) * ft_wordcounter(c, s) + 1);
	if (!rt)
		return (0);
	rt = ft_splitter(s, c, rt);
	return (rt);
}
