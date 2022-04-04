#include <criterion/criterion.h>
#include "../../includes/libft.h"

Test(strlen, len) {
	const char	*str = "Hey!";
	int	length = ft_strlen(str);
	int	expect = strlen(str);

	cr_expect(length == expect, "Ensure return string size");
}

Test(strlen, empty_str) {
	const char	*str = "\0";
	int	length = ft_strlen(str);
	int	expect = strlen(str);

	cr_expect(length == expect, "Ensure return if string is empty");
}
