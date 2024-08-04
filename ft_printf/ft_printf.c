/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:42:06 by fwechsle          #+#    #+#             */
/*   Updated: 2023/10/04 11:26:40 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putnbr_long(long long n, int fd)
{
	char	dig;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		dig = n + '0';
		write(fd, &dig, 1);
	}
}

int	ft_putnbr_unsigned(unsigned int nbr)
{
	unsigned int	buffer_nbr;
	int				length;

	length = 0;
	buffer_nbr = nbr;
	ft_putnbr_long(nbr, 1);
	if (buffer_nbr == 0)
		return (1);
	while (buffer_nbr != 0)
	{
		buffer_nbr /= 10;
		length++;
	}
	return (length);
}

int	print_format(const char str, va_list args, int i)
{
	if (str == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (str == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (str == 'p')
		ft_putnbr_base_p((unsigned long)va_arg(args, char *), &i, 1);
	else if (str == 'd' || str == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (str == 'u')
		i += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (str == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), 1, &i);
	else if (str == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), 2, &i);
	else if (str == '%')
		i += ft_putchar('%');
	else
	{
		i += ft_putchar('%');
		i += ft_putchar(str);
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	va_start(args, str);
	i = 0;
	if (str == 0)
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			while (*str == ' ' && *str != 0)
				str++;
			i = print_format(*str, args, i);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			i++;
		}
		str++;
	}
	va_end(args);
	return (i);
}
