/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 05:24:10 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/06 08:48:48 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	check_isdigit(void)
{
	char	*list[3];
	int		result;

	list[0] = "0";
	list[1] = "2";
	list[2] = "\0";
	result = check_list_integer(list);
	if (result == EXIT_SUCCESS)
	{
		printf("[check_list_integer_test.c, check_isdigit]");
		printf("- OK\n");
		return (EXIT_SUCCESS);
	}
	printf("[check_list_integer_test.c, check_isdigit]");
	printf("- Ensure returns 0 if list is integer\n");
	return (EXIT_FAILURE);
}

int	check_is_not_digit(void)
{
	char	*list[3];
	int		result;

	list[0] = "0";
	list[1] = "A";
	list[2] = "\0";
	result = check_list_integer(list);
	if (result == EXIT_FAILURE)
	{
		printf("[check_list_integer_test.c, check_is_not_digit]");
		printf("- OK\n");
		return (EXIT_SUCCESS);
	}
	printf("[check_list_integer_test.c, check_is_not_digit]");
	printf("- Ensure returns 1 if list containst other non-digit char\n");
	return (EXIT_FAILURE);
}

int	check_isnumber(void)
{
	char	*list[3];
	int		result;

	list[0] = "10";
	list[1] = "202";
	list[2] = "\0";
	result = check_list_integer(list);
	if (result == EXIT_SUCCESS)
	{
		printf("[check_list_integer_test.c, check_isnumber]");
		printf("- OK\n");
		return (EXIT_SUCCESS);
	}
	printf("[check_list_integer_test.c, check_isnumber]");
	printf("- Ensure returns 0 if is number\n");
	return (EXIT_FAILURE);
}

int	check_is_not_number(void)
{
	char	*list[3];
	int		result;

	list[0] = "10";
	list[1] = "Hey";
	list[2] = "\0";
	result = check_list_integer(list);
	if (result == EXIT_FAILURE)
	{
		printf("[check_list_integer_test.c, check_is_not_number]");
		printf("- OK\n");
		return (EXIT_SUCCESS);
	}
	printf("[check_list_integer_test.c, check_is_not_number]");
	printf("- Ensure returns 1 if if list containst other non-number char\n");
	return (EXIT_FAILURE);
}

int	check_num_with_space(void)
{
	char	*list[3];
	int		result;

	list[0] = "012  1";
	list[1] = "2  	70	80";
	list[2] = "\0";
	result = check_list_integer(list);
	if (result == EXIT_SUCCESS)
	{
		printf("[check_list_integer_test.c, check_num_with_space]");
		printf("- OK\n");
		return (EXIT_SUCCESS);
	}
	printf("[check_list_integer_test.c, check_num_with_space]");
	printf("- Ensure returns 0 if number in format string with spaces\n");
	return (EXIT_FAILURE);
}

int	check_not_num_with_space(void)
{
	char	*list[3];
	int		result;

	list[0] = "012  1";
	list[1] = "2P  	70";
	list[2] = "\0";
	result = check_list_integer(list);
	if (result == EXIT_FAILURE)
	{
		printf("[check_list_integer_test.c, check_not_num_with_space]");
		printf("- OK\n");
		return (EXIT_SUCCESS);
	}
	printf("[check_list_integer_test.c, check_not_num_with_space]");
	printf("- Ensure returns 1 if list containst other non-number char\n");
	return (EXIT_FAILURE);
}
