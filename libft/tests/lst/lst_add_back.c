#include <criterion/criterion.h>
#include "../../includes/libft.h"

Test(lst_add_back, empty_list) {
	t_list	*last_node;
	int		num;

	num = 2;
	last_node = NULL;
	ft_lstadd_back(&last_node, num);
	cr_expect(last_node->data == num, "Ensure node insertion in empty list");
	free(last_node);
}

Test(lst_add_back, empty_list_success) {
	t_list	*last_node;
	int		num;
	int		result;

	num = 2;
	last_node = NULL;
	result = ft_lstadd_back(&last_node, num);
	cr_expect(result == EXIT_SUCCESS, "Ensure return 1 if success");
	free(last_node);
}
