/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:28:40 by fwechsle          #+#    #+#             */
/*   Updated: 2023/10/25 10:42:28 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"

long	find_smallest(t_list **stack_a)
{
	long	smallest;
	t_list	*tmp;

	tmp = *stack_a;
	smallest = (long)tmp -> content;
	while (tmp -> next != NULL)
	{
		if (smallest > (long)tmp -> next -> content)
			smallest = (long)tmp -> next -> content;
		tmp = tmp -> next;
	}
	return (smallest);
}

long	find_biggest(t_list **stack_a)
{
	long	biggest;
	t_list	*tmp;

	tmp = *stack_a;
	biggest = (long)tmp -> content;
	while (tmp -> next != NULL)
	{
		if (biggest < (long)tmp -> next -> content)
			biggest = (long)tmp -> next -> content;
		tmp = tmp -> next;
	}
	return (biggest);
}

long	third_number(t_list **stack_a)
{
	t_list	*tmp;
	long	third_number;

	tmp = *stack_a;
	tmp = tmp -> next;
	third_number = (long)tmp -> next -> content;
	return (third_number);
}

int	check_sortet_list(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp -> next != NULL)
	{
		if (tmp -> content > tmp -> next -> content)
			return (1);
		tmp = tmp -> next;
	}
	return (0);
}
