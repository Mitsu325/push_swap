/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 05:24:28 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/06 15:41:21 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include "push_swap.h"

typedef struct s_check_list_int
{
	char	*list[3];
	int		result;
}		t_check_list_int;

int	push_swap_test(void);

int	check_isdigit(void);
int	check_is_not_digit(void);
int	check_isnumber(void);
int	check_is_not_number(void);
int	check_num_with_space(void);
int	check_not_num_with_space(void);

int	print_status(char *filename, char *fname, char *message, int status);

#endif
