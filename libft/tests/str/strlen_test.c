#include <criterion/criterion.h>
#include "../../includes/libft.h"

char	*str = NULL;
int		result = 0;
int		expect = 0;

Test(strlen, len) {
	str = "Hey!";
	result = ft_strlen(str);
	expect = strlen(str);
	cr_expect_eq(result, expect, "Ensure return string size");
}

Test(strlen, empty_str) {
	str = "\0";
	result = ft_strlen(str);
	expect = strlen(str);
	cr_expect_eq(result, expect, "Ensure return if string is empty");
}
