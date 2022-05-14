/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:08:02 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/12 08:11:22 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>

# define SUCCESS 0
# define FAILURE 1

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	t_list	*last_a;
	t_list	*last_b;
	int		full_size;
	int		size_a;
	int		size_b;
}		t_stack;

typedef struct s_pivot
{
	int		partition;
	int		num;
	int		half;
}		t_pivot;

// Parser
int		parser_save(char **argv, t_stack *stack);
int		check_number(char **argv);
int		check_sort(t_list *last);
int		save_number(t_stack *stack, char *number);
int		is_integer(long int number); // TODO: remove line before function convert to static

// Operation
void	push(t_list **last_to, t_list **last_from);
int		pa(t_stack *stack);
int		pb(t_stack *stack);
void	reverse_rotate(t_list **last);
int		rra(t_stack *stack);
int		rrb(t_stack *stack);
int		rrr(t_stack *stack);
void	rotate(t_list **last);
int		ra(t_stack *stack);
int		rb(t_stack *stack);
int		rr(t_stack *stack);
void	swap(t_list **last);
int		sa(t_stack *stack);
int		sb(t_stack *stack);
int		ss(t_stack *stack);

// Sort
int		sort(t_stack *stack);
int		sort_three_numbers(t_stack *stack);
int		sort_up_to_five_numbers(t_stack *stack);
void	push_smallest_number_to_b(t_stack *stack, int size_stack);
int		find_smallest_num_node(t_list *last); // TODO: remove line before function convert to static
void	push_number_to_a(t_stack *stack, int num_pushed_b);
int		sort_up_to_ten_numbers(t_stack *stack);
int		complex_sort(t_stack *stack);
void	partition_a_and_push_b(t_stack *stack);
void	quicksort(int *num, int low, int high);
void	push_small_number_pivot_to_b(t_stack *stack, t_pivot pivot);
void	sort_number_remain_a(t_stack *stack);
void	push_biggest_numbers_to_a(t_stack *stack);

// Utils
void	init_stack(t_stack *stack);
int		exit_safe_stack(t_stack *stack, int status);
void	exit_safe_parser(t_list **last, int status);
int		clean_split(char **split, int status);

#endif
