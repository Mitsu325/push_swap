#include <criterion/criterion.h>
#include "../../includes/libft.h"

Test(strchr, str_point) {
	const char	*str = "tester@mail.com";
	int	c = '@';
	char	*str_point = ft_strchr(str, c);
	char	*expect = strchr(str, c);

	cr_expect(strcmp(str_point, expect) == 0, "Ensure return string from the next char found");
}

Test(strchr, char_not_found) {
	const char	*str = "tester@mail.com";
	int	c = '#';
	char	*str_point = ft_strchr(str, c);

	cr_expect(str_point == NULL, "Ensure return NULL if the char is not found");
}

Test(strchr, str_empty) {
	const char	*str = "\0";
	int	c = '#';
	char	*str_point = ft_strchr(str, c);

	cr_expect(str_point == NULL, "Ensure return NULL if string is empty");
}
