/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayildiz <ayildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:47:56 by ayildiz           #+#    #+#             */
/*   Updated: 2024/12/22 16:03:37 by ayildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(int c);
int		ft_printf(const char *format, ...);
int		ft_putstr(char *str);
int		ft_putnbr(long i, int base, char *pase);
int		ft_ptrnbr(size_t i, size_t base, char *pase);
#endif