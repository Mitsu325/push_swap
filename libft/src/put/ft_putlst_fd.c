/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:39:24 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/11 06:01:58 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst_fd(t_list *last, int fd)
{
	t_list	*temp;
	char	*str_num;

	if (last == NULL)
		return ;
	temp = last->next;
	while (temp != last)
	{
		str_num = ft_itoa(temp->data);
		ft_putstr_fd(str_num, fd);
		ft_putstr_fd("\n", fd);
		temp = temp->next;
		free(str_num);
	}
	str_num = ft_itoa(temp->data);
	ft_putstr_fd(str_num, fd);
	ft_putstr_fd("\n", fd);
	free(str_num);
}
