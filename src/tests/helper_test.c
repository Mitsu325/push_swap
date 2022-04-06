/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:40:47 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/06 15:41:02 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	print_status(char *filename, char *fname, char *message, int status)
{
	printf("[%s, %s] - %s\n", filename, fname, message);
	return (status);
}
