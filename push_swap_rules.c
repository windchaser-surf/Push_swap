/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:08:37 by fwechsle          #+#    #+#             */
/*   Updated: 2023/10/25 10:47:09 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push_swap.h"
//swap the first two elements of stack a;
void	sa(t_list **stack_a)
{
	t_list	*note_1;
	t_list	*note_2;

	if (!stack_a || !*stack_a || !(*stack_a)-> next)
		return ;
	note_1 = *stack_a;
	note_2 = (*stack_a)-> next;
	note_1 -> next = note_2 -> next;
	note_2 -> next = note_1;
	*stack_a = note_2;
	ft_printf("sa\n");
}

//swap the first two elements of stack b;
void	sb(t_list **stack_b)
{
	t_list	*note_1;
	t_list	*note_2;

	if (!stack_b || !*stack_b || !(*stack_b)-> next)
		return ;
	note_1 = *stack_b;
	note_2 = (*stack_b)-> next;
	note_1 -> next = note_2 -> next;
	note_2 -> next = note_1;
	*stack_b = note_2;
	ft_printf("sb\n");
}

//call sa & sb at the same time
void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}

//put the first element of stack_b to a!
void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !stack_b || !(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)-> next;
	tmp -> next = *stack_a;
	*stack_a = tmp;
	ft_printf("pa\n");
}

//put the first element of stack_a to b!
void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !stack_b || !(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)-> next;
	tmp -> next = *stack_b;
	*stack_b = tmp;
	ft_printf("pb\n");
}
