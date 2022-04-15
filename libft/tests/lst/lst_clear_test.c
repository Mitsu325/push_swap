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

TestSuite(lst_clear, .init=suitesetup);

Test(lst_clear, unique_node)
{
	ft_lstadd_back(&last, first_data);
	ft_lstclear(&last);
	cr_expect(last == NULL,
	"Ensure delete unique node and clear circle linked list");
}

Test(lst_clear, multiple_node)
{
	ft_lstadd_back(&last, first_data);
	ft_lstadd_back(&last, second_data);
	ft_lstadd_back(&last, third_data);
	ft_lstclear(&last);
	cr_expect(last == NULL,
	"Ensure delete all nodes and clear circle linked list");
}
