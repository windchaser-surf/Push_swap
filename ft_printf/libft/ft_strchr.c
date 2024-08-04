/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:26:47 by fwechsle          #+#    #+#             */
/*   Updated: 2023/09/13 11:21:43 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	if ((char)c == 0)
	{
		while (*s)
			s++;
		return ((char *) s);
	}
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		else
			s++;
	}
	return (0);
}
