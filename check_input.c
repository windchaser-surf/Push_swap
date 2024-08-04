/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:17:42 by fwechsle          #+#    #+#             */
/*   Updated: 2023/10/25 17:18:05 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"

int	check_double_values(t_list *stack_a)
{
	t_list	*tmp;

	if (stack_a == NULL)
		return (0);
	while (stack_a != NULL)
	{
		tmp = stack_a -> next;
		while (tmp != NULL)
		{
			if (tmp -> content == stack_a -> content)
				return (0);
			tmp = tmp -> next;
		}
		stack_a = stack_a -> next;
	}
	return (1);
}

char	**set_and_check_arguments(char **argv, int *argc, int i)
{
	char	**arguments;

	if (argv == NULL || *argv == NULL)
		return (NULL);
	if (*argc == 2)
	{
		arguments = ft_split(argv[1], ' ');
		if (arguments == NULL)
			return (NULL);
		while (arguments[i] != NULL)
			i++;
		*argc = i;
		if (!(check_arguments_free_split(*argc, arguments, 0)))
			return (NULL);
	}
	else
	{
		arguments = argv;
		arguments++;
		*argc -= 1;
		if (!(check_arguments(*argc, arguments)))
			return (NULL);
	}
	return (arguments);
}

int	check_arguments_free_split(int argc, char **arg, int i)
{
	int	j;

	while (i < argc)
	{
		j = 0;
		if (arg[i][j] == '-' || arg[i][j] == '+')
			j++;
		while (arg[i][j] >= '0' && arg[i][j] <= '9' && arg[i][j])
			j++;
		if (arg[i][j] != 0 || j == 0)
		{
			free_arg(arg, argc);
			ft_printf("Error\n");
			return (0);
		}
		if (j > 11 || ft_atoi(arg[i]) > MAX_I || ft_atoi(arg[i]) < MIN_I)
		{
			free_arg(arg, argc);
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_arguments(int argc, char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (arg[i][j] == '-' || arg[i][j] == '+')
			j++;
		while (arg[i][j] >= '0' && arg[i][j] <= '9' && arg[i][j])
			j++;
		if (arg[i][j] != 0 || j == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		if (j > 11 || ft_atoi(arg[i]) > MAX_I || ft_atoi(arg[i]) < MIN_I)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}
