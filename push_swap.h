/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:57:13 by fwechsle          #+#    #+#             */
/*   Updated: 2023/10/25 16:21:10 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"

# ifndef MAX_I
#  define MAX_I 2147483647
# endif

# ifndef MIN_I
#  define MIN_I -2147483648
# endif

void	delete_content(void *content);
void	sort_function(t_list **stack_a, t_list **stack_b);
void	free_arg(char **arguments, int argc);
void	fill_list(t_list **stack_a, char **arguments, int argc, int check);
int		check_double_values(t_list *stack_a);
char	**set_and_check_arguments(char **argv, int *argc, int i);
int		check_arguments_free_split(int argc, char **arg, int i);
int		check_arguments(int argc, char **arg);
void	sa(t_list **lst);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
long	find_smallest(t_list **stack_a);
long	find_biggest(t_list **stack_a);
long	third_number(t_list **stack_a);
int		check_sortet_list(t_list **stack_a);
void	sort_arg_2(t_list **stack_a);
void	sort_arg_3(t_list **stack_a);
void	sort_arg_4(t_list **stack_a, t_list **stack_b);
void	sort_arg_5(t_list **stack_a, t_list **stack_b);
void	ft_sort_int_tab(long *tab, int size);
long	*convert_in_arr(t_list **stack_a);
void	convert_to_sort_index(t_list **stack_a);
int		find_max_bits(t_list **stack_a);
void	sort_arg_radix(t_list **stack_a, t_list **stack_b);

#endif