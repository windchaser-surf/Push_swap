/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:02:01 by fwechsle          #+#    #+#             */
/*   Updated: 2023/10/25 10:49:47 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push_swap.h"

//All notes switched one up, the first will be the last
void	ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*first;

	if (!stack_a || !*stack_a || !(*stack_a)-> next)
		return ;
	first = (*stack_a)-> next;
	tmp = ft_lstlast(*stack_a);
	tmp -> next = (*stack_a);
	(*stack_a)-> next = NULL;
	*stack_a = first;
	ft_printf("ra\n");
}

//same like above but in stack_b
void	rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*first;

	if (!stack_b || !*stack_b || !(*stack_b)-> next)
		return ;
	first = (*stack_b)-> next;
	tmp = ft_lstlast(*stack_b);
	tmp -> next = (*stack_b);
	(*stack_b)-> next = NULL;
	*stack_b = first;
	ft_printf("rb\n");
}

//call ra and rb at the same time
void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}

//Shift down all elements, the last will be the first
void	rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack_a || !*stack_a || !(*stack_a)-> next)
		return ;
	second_last = *stack_a;
	last = ft_lstlast(*stack_a);
	while (second_last -> next != last)
		second_last = second_last -> next;
	last -> next = *stack_a;
	second_last -> next = NULL;
	*stack_a = last;
	ft_printf("rra\n");
}

//same like a above, just wie stack_b
void	rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack_b || !*stack_b || !(*stack_b)-> next)
		return ;
	second_last = *stack_b;
	last = ft_lstlast(*stack_b);
	while (second_last -> next != last)
		second_last = second_last -> next;
	last -> next = *stack_b;
	second_last -> next = NULL;
	*stack_b = last;
	ft_printf("rrb\n");
}
