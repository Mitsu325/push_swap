/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 03:21:39 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/03/31 03:24:48 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*s_alloc;

	len = ft_strlen(s1);
	s_alloc = (char *)malloc((len + 1) * sizeof(char));
	if (!s_alloc)
		return (NULL);
	ft_strcpy(s_alloc, s1, len);
	return (s_alloc);
}
