/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:59:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/03 12:18:31 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (EXIT_FAILURE);
	printf("%s\n", argv[1]);
	int num = ft_isdigit(8 + '0');
	printf("%d\n", num);
	printf("====================\n");
	int limit_max_lib = ft_atoi("   -2147+4836");
	printf("lib - %d\n", limit_max_lib);
	int limit_max = atoi("   -2147+4836");
	printf("main - %d\n", limit_max);
	return (EXIT_SUCCESS);
}
