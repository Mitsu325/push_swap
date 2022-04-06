/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 01:27:18 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/06 08:43:47 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define SPC 0x020
# define TAB 0x009
# define CR 0x00D

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		is_white_space(int c);

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
void	ft_strcpy(char *dst, const char *src, int dstsize);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, int start, int len);

#endif
