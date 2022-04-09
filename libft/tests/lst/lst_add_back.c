#include <criterion/criterion.h>
#include "../../includes/libft.h"
#include <stdio.h>

Test(lst_add_back, empty_list)
{
	t_list *last_node;
	int num;

	num = 2;
	last_node = NULL;
	ft_lstadd_back(&last_node, num);
	cr_expect(last_node->data == num, "Ensure node insertion in empty list");
	free(last_node);
}

Test(lst_add_back, empty_list_success)
{
	t_list *last_node;
	int num;
	int result;

	num = 2;
	last_node = NULL;
	result = ft_lstadd_back(&last_node, num);
	cr_expect(result == EXIT_SUCCESS, "Ensure return 1 if success");
	free(last_node);
}

Test(lst_add_back, list_with_node)
{
	t_list *last_node;
	int num;
	t_list *temp;
	t_list *current;

	num = 2;
	last_node = NULL;
	ft_lstadd_back(&last_node, num);
	num = 50;
	ft_lstadd_back(&last_node, num);
	num = -1;
	ft_lstadd_back(&last_node, num);
	cr_expect(last_node->data == -1,
	"Ensure node insertion at the end of the list and change pointer to last node");
	cr_expect(last_node->next->data == 2,
	"Ensure node insertion at the end of the list and change pointer to last node");
	cr_expect(last_node->next->next->data == 50,
	"Ensure node insertion at the end of the list and change pointer to last node");
	current = last_node->next;
	while (current != last_node)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(last_node);
}
