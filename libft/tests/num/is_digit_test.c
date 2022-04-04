#include <criterion/criterion.h>
#include "../../includes/libft.h"

Test(isdigit, truthy) {
	int	c = '2';
	int	isdigit = ft_isdigit(c);
	int	expect = 1;

	cr_expect(isdigit == expect, "Ensure return 1 if char is digit");
}

Test(isdigit, falsy) {
	int	c = 2;
	int	isdigit = ft_isdigit(c);
	int	expect = 0;

	cr_expect(isdigit == expect, "Ensure return 0 if char is not digit");
}
