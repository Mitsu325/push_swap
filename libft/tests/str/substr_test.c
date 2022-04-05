#include <criterion/criterion.h>
#include "../../includes/libft.h"

Test(substr, create) {
	const char	*str = "Hey MarVin!";
	int	first_index = 4;
	int	result_length = 6;
	char	*result = ft_substr(str, first_index, result_length);

	cr_expect_str_eq(result, "MarVin", "Ensure create a substring from first index with length");
	free(result);
}

Test(substr, create_longer_length) {
	const char	*str = "Hey MarVin!";
	int	first_index = 4;
	int	result_length = 15;
	char	*result = ft_substr(str, first_index, result_length);

	cr_expect_str_eq(result, "MarVin!", "Ensure create a substring respecting the original string size");
	free(result);
}

Test(substr, str_null) {
	const char	*str = "\0";
	int	first_index = 4;
	int	result_length = 6;
	char	*result = ft_substr(str, first_index, result_length);

	cr_expect_str_eq(result, "", "Ensure returns empty if string is null");
	free(result);
}

Test(substr, first_index_greater) {
	const char	*str = "Hey MarVin!";
	int	first_index = 15;
	int	result_length = 6;
	char	*result = ft_substr(str, first_index, result_length);

	cr_expect_str_eq(result, "", "Ensure returns empty if first index is greater than string size");
	free(result);
}
