/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:50:56 by ayildiz           #+#    #+#             */
/*   Updated: 2024/12/22 19:04:27 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*after_nl(char *s, char c)
{
	char	*str;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(s) - i) + 1);
	if (!str)
		return (NULL);
	i++;
	while (s[i])
		str[j++] = s[i++];
}

static char	*next_line(int fd, char *s)
{
	char	*buf;
	int		i;
	
	buf = (char *)malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_strchr(s, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		s = ft_strjoin(s, buf);
	}
	free(buf);
	return (s);
}

char	*get_next_line(int fd)
{
	char			*str;
	static char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = next_line(fd, line);
	if (line)
	{
		str = before_nl(line, '\n');
		line = after_nl(line, '\n');
	}
	return (NULL);
}