/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:34:47 by fwechsle          #+#    #+#             */
/*   Updated: 2023/10/04 11:26:48 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putnbr_base_p(unsigned long long nbr, int *i, int first_print)
{
	char	base [17];

	if (nbr == 0 && first_print == 1)
	{
		write(1, "(nil)", 5);
		*i += 5;
		return ;
	}
	if (first_print == 1)
	{
		write(1, "0x", 2);
		*i += 2;
	}
	ft_strlcpy(base, "0123456789abcdef", 17);
	if (nbr > 15)
	{
		ft_putnbr_base_p(nbr / 16, i, 0);
		ft_putnbr_base_p(nbr % 16, i, 0);
	}
	else
	{
		*i += 1;
		write (1, &base[nbr], 1);
	}
}

void	ft_putnbr_base(unsigned long long nbr, int check, int *i)
{
	char	base [17];

	if (check == 2)
		ft_strlcpy(base, "0123456789ABCDEF", 17);
	else if (check == 1)
		ft_strlcpy(base, "0123456789abcdef", 17);
	if (nbr > 15)
	{
		ft_putnbr_base(nbr / 16, check, i);
		ft_putnbr_base(nbr % 16, check, i);
	}
	else
	{
		*i += 1;
		write (1, &base[nbr], 1);
	}
}

int	ft_putstr(char *s)
{
	int	length;

	length = 0;
	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(1, s, 1);
		s++;
		length++;
	}
	return (length);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(long long nbr)
{
	int	buffer_nbr;
	int	length;

	length = 0;
	buffer_nbr = nbr;
	ft_putnbr_fd(nbr, 1);
	if (buffer_nbr == 0)
		return (1);
	if (buffer_nbr < 0)
		length += 1;
	while (buffer_nbr != 0)
	{
		buffer_nbr /= 10;
		length++;
	}
	return (length);
}
