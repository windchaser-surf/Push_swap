/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:20:45 by fwechsle          #+#    #+#             */
/*   Updated: 2023/10/26 10:22:23 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"

void	delete_content(void *content)
{
	content = NULL;
	if (content == NULL)
		return ;
}

void	sort_function(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sort_arg_2(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_arg_3(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_arg_4(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_arg_5(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) > 5)
		sort_arg_radix(stack_a, stack_b);
}

void	free_arg(char **arguments, int argc)
{
	int	i;

	i = 0;
	while (i <= argc)
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}

void	fill_list(t_list **stack_a, char **arguments, int argc, int check)
{
	int	i;

	i = 0;
	while (argc > i)
	{
		ft_lstadd_back(&*stack_a, ft_lstnew((void *)ft_atoi(arguments[i])));
		i++;
	}
	if (check < 3)
		free_arg(arguments, argc);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**arguments;
	int		check;

	check = argc;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	arguments = set_and_check_arguments(argv, &argc, 0);
	if (arguments == NULL)
		return (1);
	fill_list(&stack_a, arguments, argc, check);
	if (!(check_double_values(stack_a)))
	{
		ft_printf("Error\n");
		ft_lstclear(&stack_a);
		return (1);
	}
	convert_to_sort_index(&stack_a);
	sort_function(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
