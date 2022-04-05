#include <criterion/criterion.h>
#include "../../includes/libft.h"

char	*str = NULL;
int		size_copy = 0;
char	*expect = NULL;

void	suitesetup(void)
{
	str = "Hey MarVin!";
	return ;
}

TestSuite(strcpy, .init=suitesetup);

Test(strcpy, copy_str) {
	char	dst[3];

	size_copy = 3;
	expect = "He\0";
	ft_strcpy(dst, str, size_copy);
	cr_expect_str_eq(dst, expect,
	"Ensure copy the string in the correct amount of char including the zero char");
}

Test(strcpy, str_zero) {
	char	dst[1];

	size_copy = 0;
	ft_strcpy(dst, str, size_copy);
	cr_expect_str_empty(dst, "Ensure copy the string if size is zero");
}

Test(strcpy, str_one) {
	char	dst[1];

	size_copy = 1;
	ft_strcpy(dst, str, size_copy);
	cr_expect_str_empty(dst, "Ensure copy the string if size is one");
}
