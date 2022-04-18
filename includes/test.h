/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 05:24:28 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/18 06:32:53 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <string.h>
# include "push_swap.h"

// Unit Test

int	parser_save_test(void);
int	check_list_int(void);
int	check_is_int(void);
int	check_save(void);
int	check_sort_test(void);

int	operation_test(void);
int	swap_test(void);
int	push_test(void);

// Test Integration
int	parser_save_test_i(void);

// Helper
int	print_status(char *filename, char *fname, char *message, int status);

#endif
