#include <criterion/criterion.h>
#include "../../includes/libft.h"

char	*str = NULL;
int		char_search = 0;
char	*str_point = NULL;
char	*expect = NULL;

void	suitesetup(void)
{
	str = "tester@mail.com";
	return ;
}

TestSuite(strchr, .init=suitesetup);

Test(strchr, str_point) {
	char_search = '@';
	str_point = ft_strchr(str, char_search);
	expect = strchr(str, char_search);
	cr_expect_str_eq(str_point, expect, "Ensure return string from the next char found");
}

Test(strchr, char_not_found) {
	char_search = '#';
	str_point = ft_strchr(str, char_search);
	cr_expect_null(str_point, "Ensure return NULL if the char is not found");
}

Test(strchr, str_empty) {
	str = "\0";
	char_search = '#';
	str_point = ft_strchr(str, char_search);
	cr_expect_null(str_point, "Ensure return NULL if string is empty");
}
