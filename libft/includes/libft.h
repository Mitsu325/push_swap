/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 01:27:18 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/06 06:45:43 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define SPC 0x020
# define TAB 0x009
# define CR 0x00D

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

int			ft_isdigit(int c);
int			ft_issignal(int c);
int			ft_isspace(int c);

int			ft_lstadd_back(t_list **last, int data);
void		ft_lstclear(t_list **last);

long int	ft_atoi(const char *str);
int			is_white_space(int c);
char		*ft_itoa(int n);

char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
void		ft_strcpy(char *dst, const char *src, int dstsize);
char		*ft_strdup(const char *s1);
int			ft_strlen(const char *str);
char		*ft_substr(char const *s, int start, int len);

void		ft_putchar_fd(char ch, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putlst_fd(t_list *last, int fd);

#endif
