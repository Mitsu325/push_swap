/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 05:24:28 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/14 05:26:01 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include "push_swap.h"

int	push_swap_test(void);

int	check_isdigit(void);
int	check_is_not_digit(void);
int	check_isnumber(void);
int	check_is_not_number(void);
int	check_num_with_space(void);
int	check_not_num_with_space(void);
int	check_num_with_positive_sign(void);
int	check_num_with_negative_sign(void);

int	check_is_integer(void);
int	check_max_integer(void);
int	check_min_integer(void);

int	check_save_number(void);
int	check_save_number_with_space(void);
int	check_save_max_int(void);
int	check_save_min_int(void);
int	check_save_greater_max_int(void);
int	check_save_less_min_int(void);
int	check_save_duplicate(void);

int	check_sort_null(void);
int	check_sort_one_number(void);
int	check_sort_multiple_number(void);
int	check_not_sort(void);

int	print_status(char *filename, char *fname, char *message, int status);

#endif
