/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:14:11 by felix             #+#    #+#             */
/*   Updated: 2023/10/25 12:27:20 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	ft_sort_int_tab(long *tab, int size)
{
	int		io;
	int		ii;
	int		loop;
	long	temp;

	ii = 0;
	io = 0;
	loop = size - 1;
	while (io < loop)
	{
		while (ii < loop)
		{
			if (tab[ii] > tab[ii + 1])
			{
				temp = tab[ii];
				tab[ii] = tab[ii + 1];
				tab[ii + 1] = temp;
			}
			ii++;
		}
		ii = 0;
		io++;
	}
}

long	*convert_in_arr(t_list **stack_a)
{
	int		len;
	long	*result;
	t_list	*tmp;

	if (stack_a == NULL || *stack_a == NULL)
		return (NULL);
	tmp = *stack_a;
	len = ft_lstsize(*stack_a);
	result = (long *)malloc(sizeof(long) * (len));
	if (!result)
		return (NULL);
	len = 0;
	while (tmp != NULL)
	{
		result[len] = (long)tmp -> content;
		len++;
		tmp = tmp -> next;
	}
	ft_sort_int_tab(result, len);
	return (result);
}

void	convert_to_sort_index(t_list **stack_a)
{
	long	*arr;
	t_list	*tmp;
	long	i;

	tmp = *stack_a;
	arr = convert_in_arr(stack_a);
	if (arr == NULL)
		return ;
	while (tmp != NULL)
	{
		i = 0;
		while (arr[i] != (long) tmp -> content)
			i++;
		if (arr[i] == (long) tmp -> content)
			tmp -> content = (void *)i;
		tmp = tmp -> next;
	}
	free (arr);
}

int	find_max_bits(t_list **stack_a)
{
	long	biggest;
	int		i;

	i = 0;
	biggest = find_biggest(stack_a);
	while (biggest >> i != 0)
		i++;
	return (i);
}

void	sort_arg_radix(t_list **stack_a, t_list **stack_b)
{
	int	max_bits;
	int	i;
	int	lst_size;
	int	n;

	i = 0;
	if (!(check_sortet_list(stack_a)))
		return ;
	lst_size = ft_lstsize(*stack_a);
	max_bits = find_max_bits(stack_a);
	while (i < max_bits)
	{
		n = 0;
		while (n < lst_size)
		{
			if ((((long)(*stack_a)-> content >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			n++;
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		i++;
	}
}
