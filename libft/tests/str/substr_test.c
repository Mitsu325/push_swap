#include <criterion/criterion.h>
#include "../../includes/libft.h"

char	*str = NULL;
int		first_index = 0;
int		result_length = 0;
char	*result = NULL;
char	*expect = NULL;

void	suitesetup(void)
{
	str = "Hey MarVin!";
	return ;
}

TestSuite(substr, .init=suitesetup);

Test(substr, create) {
	first_index = 4;
	result_length = 6;
	result = ft_substr(str, first_index, result_length);
	expect = "MarVin";
	cr_expect_str_eq(result, expect, "Ensure create a substring from first index with length");
	free(result);
}

Test(substr, create_longer_length) {
	first_index = 4;
	result_length = 15;
	result = ft_substr(str, first_index, result_length);
	expect = "MarVin!";
	cr_expect_str_eq(result, expect, "Ensure create a substring respecting the original string size");
	free(result);
}

Test(substr, str_null) {
	str = "\0";
	first_index = 4;
	result_length = 6;
	result = ft_substr(str, first_index, result_length);
	cr_expect_str_empty(result, "Ensure returns empty if string is null");
	free(result);
}

Test(substr, first_index_greater) {
	first_index = 15;
	result_length = 6;
	result = ft_substr(str, first_index, result_length);
	cr_expect_str_empty(result, "Ensure returns empty if first index is greater than string size");
	free(result);
}
