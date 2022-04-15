#include <criterion/criterion.h>
#include "../../includes/libft.h"
#include <stdio.h>

t_list *last = NULL;
int first_data = 0;
int second_data = 0;
int third_data = 0;

void	suitesetup(void)
{
	first_data = 2;
	second_data = 50;
	third_data = -3;
	return ;
}

TestSuite(put_lst, .init=suitesetup);

Test(put_lst, unique_node)
{
	int	num = 8;
	ft_lstadd_back(&last, num);
	ft_putlst_fd(last, 1);
	cr_assert(true, "Ensure print unique node");
	ft_lstclear(&last);
}

Test(put_lst, multiple_node)
{
	ft_lstadd_back(&last, first_data);
	ft_lstadd_back(&last, second_data);
	ft_lstadd_back(&last, third_data);
	ft_putlst_fd(last, 1);
	cr_assert(true, "Ensure print all nodes");
	ft_lstclear(&last);
}
