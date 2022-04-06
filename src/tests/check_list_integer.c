/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 05:24:10 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/06 07:11:36 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	check_is_digit(void)
{
	char	*list[3];
	int		result;

	list[0] = "0";
	list[1] = "2";
	list[2] = "\0";
	result = check_list_integer(list);
	if (result == EXIT_SUCCESS)
	{
		printf("[check_list_integer_test.c, check_is_digit]");
		printf("- OK\n");
		return (EXIT_SUCCESS);
	}
	printf("[check_list_integer_test.c, check_is_digit]");
	printf("- Ensure returns 0 if list is integer\n");
	return (EXIT_FAILURE);
}
