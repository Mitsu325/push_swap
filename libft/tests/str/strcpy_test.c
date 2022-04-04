#include <criterion/criterion.h>
#include "../../includes/libft.h"

Test(strcpy, copy_str) {
	const char	*expect = "He\0";
	const char	*str = "Hey MarVin!";
	int	size_copy = 3;
	char	dst[size_copy];

	ft_strcpy(dst, str, size_copy);

	cr_expect(strcmp(dst, expect) == 0,
	"Ensure copy the string in the correct amount of char including the zero char");
}

Test(strcpy, str_zero) {
	const char	*expect = "\0";
	const char	*str = "Hey MarVin!";
	int	size_copy = 0;
	char	dst[size_copy];

	ft_strcpy(dst, str, size_copy);

	cr_expect(strcmp(dst, expect) == 0,
	"Ensure copy the string if size is zero");
}

Test(strcpy, str_one) {
	const char	*expect = "\0";
	const char	*str = "Hey MarVin!";
	int	size_copy = 1;
	char	dst[size_copy];

	ft_strcpy(dst, str, size_copy);

	cr_expect(strcmp(dst, expect) == 0,
	"Ensure copy the string if size is one");
}
