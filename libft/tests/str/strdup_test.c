#include <criterion/criterion.h>
#include "../../includes/libft.h"

char	*str = NULL;
char	*result = NULL;

Test(strdup, copy_str) {
	str = "Hey MarVin!";
	result = ft_strdup(str);
	cr_assert(result, "Ensure duplicate a string");
	free(result);
}

Test(strdup, str_null) {
	str = "\0";
	result = ft_strdup(str);
	cr_assert(result, "Ensure duplicate a string if string is zero char");
	free(result);
}
