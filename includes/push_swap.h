/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:08:02 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/15 07:14:11 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

// # define EXIT_SUCCESS 0
// # define EXIT_FAILURE 1

# define INT_MAX 2147483647
# define INT_MIN -2147483648

int	check_list_integer(char **numbers);
int	is_integer(long int	number);
int	save(t_list **last, char *number);

int	check_sort(t_list *last);

int	parser_save(char **argv, t_list **last);

#endif
