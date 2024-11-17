/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:46:28 by ayildiz           #+#    #+#             */
/*   Updated: 2024/11/13 17:52:30 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (fd >= 0)
	{
		i = 0;
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}