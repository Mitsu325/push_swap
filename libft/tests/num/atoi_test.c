#include <criterion/criterion.h>
#include "../../includes/libft.h"

char		*str = NULL;
long int	result = 0;
long int	expect = 0;

Test(atoi, positive_num) {
	str = "127";
	result = ft_atoi(str);
	expect = atoi(str);
	cr_expect_eq(result, expect, "Ensure returns a positive number");
}

Test(atoi, negative_num) {
	str = "-127";
	result = ft_atoi(str);
	expect = atoi(str);
	cr_expect_eq(result, expect, "Ensure returns a negative number");
}

Test(atoi, integer_max) {
	str = "+2147483647";
	result = ft_atoi(str);
	expect = atoi(str);
	cr_expect_eq(result, expect, "Ensure returns a integer max number");
}

Test(atoi, integer_min) {
	str = "-2147483648";
	result = ft_atoi(str);
	expect = atoi(str);
	cr_expect_eq(result, expect, "Ensure returns a min integer");
}

Test(atoi, greater_integer_max) {
	str = "+2147483650";
	result = ft_atoi(str);
	expect = 2147483650;
	cr_expect_eq(result, expect, "Ensure returns greater than the max integer");
}

Test(atoi, less_integer_min) {
	str = "-2147483650";
	result = ft_atoi(str);
	expect = -2147483650;
	cr_expect_eq(result, expect, "Ensure returns less than the min integer");
}

Test(atoi, signal) {
	str = "127+-098";
	result = ft_atoi(str);
	expect = atoi(str);
	cr_expect_eq(result, expect, "Ensure consecutive signal handling. Disregards the numbers after the sign");
}

Test(atoi, negative_signal) {
	str = "--127098";
	result = ft_atoi(str);
	expect = atoi(str);
	cr_expect_eq(result, expect, "Ensure consecutive negative signal handling. Disregards the numbers after the sign or return 0.");
}
