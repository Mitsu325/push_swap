#include <criterion/criterion.h>
#include "../../includes/libft.h"

int	c = 0;
int	result = 0;
int	expect = 0;

Test(isdigit, truthy) {
	c = '2';
	result = ft_isdigit(c);
	expect = 1;
	cr_expect_eq(result, expect, "Ensure return 1 if char is digit");
}

Test(isdigit, falsy) {
	c = 2;
	result = ft_isdigit(c);
	expect = 0;
	cr_expect_eq(result, expect, "Ensure return 0 if char is not digit");
}
