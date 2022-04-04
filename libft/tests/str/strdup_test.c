#include <criterion/criterion.h>
#include "../../includes/libft.h"

Test(strdup, copy_str) {
	const char	*str = "Hey MarVin!";
	char	*result = ft_strdup(str);

	cr_assert(result, "Ensure duplicate a string");
	free(result);
}

Test(strdup, str_null) {
	const char	*str = "\0";
	char	*result = ft_strdup(str);

	cr_assert(result, "Ensure duplicate a string if string is zero char");
	free(result);
}
