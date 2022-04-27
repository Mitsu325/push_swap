/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:19:20 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/26 05:50:43 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	sort_test(void)
{
	if (two_number_test())
		return (FAILURE);
	if (three_number_test())
		return (FAILURE);
	if (five_number_test())
		return (FAILURE);
	if (ten_number_test())
		return (FAILURE);
	return (SUCCESS);
}
