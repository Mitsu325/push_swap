/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 05:26:14 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/16 17:36:05 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	parser_save_test(void)
{
	if (check_list_int())
		return (FAILURE);
	if (check_is_int())
		return (FAILURE);
	if (check_save())
		return (FAILURE);
	if (check_sort_test())
		return (FAILURE);
	return (SUCCESS);
}
