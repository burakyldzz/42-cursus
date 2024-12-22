/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:31:03 by ayildiz           #+#    #+#             */
/*   Updated: 2024/12/22 20:05:16 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char *ft_strjoin(char *s1, char*s2)
{
    char *str;
    int     i;
    int     j;
    
    i = -1;
    j = 0;
    if (!s1)
    {
        s1 = (char *)malloc(sizeof(char));
        s1[0] = '\0';
    }
    if (!s2)
        return(NULL);
    str = (char *)malloc(sizeof(s1) + sizeof(s2) + 1);
    if (!str)
        return (NULL);
    while (s1[++i])
        str[i] = s1[i];
    while (s2[j])
        str[i++] = s2[j++];
    str[i] = '\0';
    free(s1);
    return (str);
}

char    *ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	
	while (*s)
	{
		if (*s++ == (char)c)
			return (s);
	}
	if (c == '\0')
		return (s);
	return (NULL);
}
