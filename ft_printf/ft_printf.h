/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:33:02 by fwechsle          #+#    #+#             */
/*   Updated: 2023/09/28 11:18:49 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putnbr_base_p(unsigned long long nbr, int *i, int first_print);
void	ft_putnbr_base(unsigned long long nbr, int check, int *i);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(long long nbr);
void	ft_putnbr_long(long long n, int fd);
int		ft_putnbr_unsigned(unsigned int nbr);
int		print_format(const char str, va_list args, int i);

#endif
