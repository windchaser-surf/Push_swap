/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:36:07 by fwechsle          #+#    #+#             */
/*   Updated: 2023/10/25 11:47:54 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"

void	sort_arg_2(t_list **stack_a)
{
	if ((long)(*stack_a)-> content > (long)(*stack_a)-> next -> content)
		sa(stack_a);
}

void	sort_arg_3(t_list **stack_a)
{
	long	smallest;
	long	biggest;
	t_list	*last;

	last = ft_lstlast(*stack_a);
	smallest = find_smallest(stack_a);
	biggest = find_biggest(stack_a);
	if ((long)last -> content != smallest && (long)last -> content != biggest)
	{
		if ((long)(*stack_a)-> content == biggest)
			ra(stack_a);
		else
		{
			rra(stack_a);
			sa(stack_a);
		}
	}
	else
	{
		if ((long)(*stack_a)-> content > (long)(*stack_a)-> next -> content)
			sa(stack_a);
		if ((long)(*stack_a)-> content > (long)ft_lstlast(*stack_a)-> content)
			rra(stack_a);
	}
}

void	sort_arg_4(t_list **stack_a, t_list **stack_b)
{
	if (!(check_sortet_list(stack_a)))
		return ;
	if ((long)(*stack_a)-> content == find_smallest(stack_a))
		pb(stack_a, stack_b);
	else if ((long)(*stack_a)-> next -> content == find_smallest(stack_a))
	{
		sa(stack_a);
		if (check_sortet_list(stack_a))
			pb(stack_a, stack_b);
	}
	else if ((long)ft_lstlast(*stack_a)-> content == find_smallest(stack_a))
	{
		rra(stack_a);
		if (check_sortet_list(stack_a))
			pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	if ((check_sortet_list(stack_a)))
		sort_arg_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_arg_5(t_list **stack_a, t_list **stack_b)
{
	if (!(check_sortet_list(stack_a)))
		return ;
	if ((long)(*stack_a)-> content == find_smallest(stack_a))
		pb(stack_a, stack_b);
	else if ((long)(*stack_a)-> next -> content == find_smallest(stack_a))
		sa(stack_a);
	else if (third_number(stack_a) == find_smallest(stack_a))
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if ((long)ft_lstlast(*stack_a)-> content == find_smallest(stack_a))
		rra(stack_a);
	else
	{
		rra(stack_a);
		rra(stack_a);
	}
	if (check_sortet_list(stack_a) && *stack_b == NULL)
		pb(stack_a, stack_b);
	sort_arg_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

//next step! write alg_4 and alg_5 
//funktion auslagern für die suche von smallest und biggest! 
//Müsste eigentl bei allen gleich sein.