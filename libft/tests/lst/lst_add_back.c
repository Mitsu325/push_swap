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

TestSuite(split, .init=suitesetup);

Test(lst_add_back, empty_list)
{
	ft_lstadd_back(&last, first_data);
	cr_expect(last->data == first_data,
	"Ensure node insertion in empty list");
	free(last);
}

Test(lst_add_back, empty_list_success)
{
	int result;

	result = ft_lstadd_back(&last, first_data);
	cr_expect(result == EXIT_SUCCESS, "Ensure return 1 if success");
	free(last);
}

Test(lst_add_back, list_with_node)
{
	t_list *temp;
	t_list *current;

	ft_lstadd_back(&last, first_data);
	ft_lstadd_back(&last, second_data);
	ft_lstadd_back(&last, third_data);
	cr_expect(last->data == third_data,
	"Ensure node insertion at the end of the list and change pointer to last node");
	cr_expect(last->next->data == first_data,
	"Ensure node insertion at the end of the list and change pointer to last node");
	cr_expect(last->next->next->data == second_data,
	"Ensure node insertion at the end of the list and change pointer to last node");
	current = last->next;
	while (current != last)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(last);
}
