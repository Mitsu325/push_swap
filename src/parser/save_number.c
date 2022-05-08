/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 06:58:42 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/06 07:49:32 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: check_consecutive_sign
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Check if the string contains consecutive sign.
** PARAMETERS:
** #str. The string
** RETURN VALUES:
** Return 0 if the string has no consecutive sign and 1 if consecutive sign.
** -------------------------------------------------------------------------- */
static int	check_consecutive_sign(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == '+' || *str == '-')
			count++;
		if (count > 1)
			return (FAILURE);
		str++;
	}
	return (SUCCESS);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: check_has_digit
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Check if the string contains digit.
** PARAMETERS:
** #str. The string
** RETURN VALUES:
** Return 0 if the string has digit and 1 if not.
** -------------------------------------------------------------------------- */
static int	check_has_digit(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
			count++;
		str++;
	}
	if (count)
		return (SUCCESS);
	return (FAILURE);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: is_integer
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Check the number is within the range of integer.
** PARAMETERS:
** #number. The long int
** RETURN VALUES:
** Return 0 if the number within range and 0 if not.
** -------------------------------------------------------------------------- */
int	is_integer(long int number) // TODO: convert function to static before remove tester
{
	if (number >= INT_MIN && number <= INT_MAX)
		return (SUCCESS);
	return (FAILURE);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: check_duplicate
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Check the data already exists in the list.
** PARAMETERS:
** #last. The t_list struct
** #data. The long int
** RETURN VALUES:
** Return 0 if the data contains in the list and 1 if not.
** -------------------------------------------------------------------------- */
static int	check_duplicate(t_list **last, long int data)
{
	t_list	*temp;

	if (*last == NULL)
		return (SUCCESS);
	temp = (*last)->next;
	while (temp != *last)
	{
		if (temp->data == data)
			return (FAILURE);
		temp = temp->next;
	}
	if (temp->data == data)
		return (FAILURE);
	return (SUCCESS);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: save_number
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Splits the string with the space char and checks if it has consecutive signs
** or if it has no digit. Converts string number to int and checks if it is
** within range integer and has duplicate numbers in list. Then add the number
** to the end of the list.
** PARAMETERS:
** #stack. The t_stack struct
** #number. The string
** RETURN VALUES:
** Return 0 if successful and 1 if failure.
** -------------------------------------------------------------------------- */
int	save_number(t_stack *stack, char *number)
{
	long int	data;
	char		**split_num;
	int			i;

	split_num = ft_split(number, ' ');
	i = 0;
	while (*(split_num + i))
	{
		if (check_consecutive_sign(*(split_num + i)))
			return (clean_split(split_num, FAILURE));
		if (check_has_digit(*(split_num + i)))
			return (clean_split(split_num, FAILURE));
		data = ft_atoi(*(split_num + i));
		if (is_integer(data))
			return (clean_split(split_num, FAILURE));
		if (check_duplicate(&stack->last_a, data))
			return (clean_split(split_num, FAILURE));
		if (ft_lstadd_back(&stack->last_a, data))
			return (clean_split(split_num, FAILURE));
		i++;
	}
	stack->full_size += i;
	return (clean_split(split_num, SUCCESS));
}
