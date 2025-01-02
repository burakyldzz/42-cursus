/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:50:56 by ayildiz           #+#    #+#             */
/*   Updated: 2024/12/28 15:59:36 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char *next_line)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!*next_line)
		return (NULL);
	while (next_line[i] && next_line[i] != '\n')
		i++;
	new_str = malloc(sizeof(char) * (i + 2));
	if (!new_str)
		return (NULL);
	i = 0;
	while (next_line[i] && next_line[i] != '\n')
	{
		new_str[i] = next_line[i];
		i++;
	}
	if (next_line[i] == '\n')
	{
		new_str[i] = next_line[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char	*ft_to_next_line(char *next_line)
{
	int		i;
	int		j;
	char	*new_line;

	if (!next_line)
		return (NULL);
	i = 0;
	j = 0;
	while (next_line[i] && next_line[i] != '\n')
		i++;
	if (!next_line[i])
	{
		free(next_line);
		return (NULL);
	}
	new_line = malloc(sizeof(char) * ft_strlen(next_line) - i);
	if (!new_line)
		return (NULL);
	i++;
	while (next_line[i])
		new_line[j++] = next_line[i++];
	new_line[j] = '\0';
	free(next_line);
	return (new_line);
}

static char	*ft_get_str(int fd, char *next_line)
{
	int		control;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	control = 1;
	while (!ft_find_nl(next_line, '\n') && control != 0)
	{
		control = read(fd, buffer, BUFFER_SIZE);
		if (control == -1)
		{
			free(buffer);
			free(next_line);
			buffer = NULL;
			return (NULL);
		}
		buffer[control] = '\0';
		next_line = ft_strjoin(next_line, buffer);
		if (!next_line)
			return (NULL);
	}
	free(buffer);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char		*next_line;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = ft_get_str(fd, next_line);
	if (!next_line)
		return (NULL);
	line = ft_get_line(next_line);
	next_line = ft_to_next_line(next_line);
	return (line);
}
