/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:49:10 by ayildiz           #+#    #+#             */
/*   Updated: 2024/10/26 16:41:43 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	*strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize == 0 || dstsize <= dstlen)
		return (srclen + dstsize);
	i = 0;
	while (src[i] != '\0' && i < dstsize - dstlen - 1)
	{
		dst[dstlen] = src[i];
		i++;
		dstlen++;
	}
	dst[dstlen] = '\0';
	return (srclen + dstlen);
}
