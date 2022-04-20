/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:08:02 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/20 05:14:43 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

# define SUCCESS 0
# define FAILURE 1

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	t_list	*last;
	int		size;
}		t_stack;

int	parser_save(char **argv, t_stack *stack);
int	check_number(char **numbers);
int	save_number(t_stack *stack, char *number);
int	is_integer(long int number);
int	check_sort(t_list *last);

void	swap(t_list **last);
void	push(t_list **last_to, t_list **last_from);
void	rotate(t_list **last);

#endif
