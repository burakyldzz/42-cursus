/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:38:58 by ayildiz           #+#    #+#             */
/*   Updated: 2024/10/29 15:08:23 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	strat;
	size_t	end;
	char	*str;

	str = 0;
	if (s1 != '\0' && set != '\0')
	{
		strat = 0;
		end = ft_strlen(s1);
		while (s1[strat] && ft_strchr(set, s1[strat]))
			strat++;
		while (s1[end -1] && ft_strchr(set, s1[end - 1]))
			end--;
		str = malloc((end - strat + 1) * sizeof(char));
		if (str)
			ft_strlcpy(str, &s1[strat], end - strat + 1);
	}
	return (str);
}
