/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:39:24 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/09 19:12:25 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst_fd(t_list *last, int fd)
{
	t_list	*temp;

	if (last == NULL)
		return ;
	temp = last->next;
	while (temp != last)
	{
		// need use ft_itoa (convert int to string)
		// ft_putstr_fd(temp->data, fd);
		ft_putstr_fd("1", fd);
		ft_putstr_fd("\n", fd);
		temp = temp->next;
	}
	ft_putstr_fd("1", fd);
	ft_putstr_fd("\n", fd);
}
