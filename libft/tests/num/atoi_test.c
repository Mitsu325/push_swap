#include <criterion/criterion.h>
#include "../../includes/libft.h"

Test(atoi, positive_num) {
	const char	*str = "127";
	int	my_num = ft_atoi(str);
	int	num_expect = atoi(str);

	cr_expect(my_num == num_expect, "Ensure returns a positive number");
}

Test(atoi, negative_num) {
	const char	*str = "-127";
	int	my_num = ft_atoi(str);
	int	num_expect = atoi(str);

	cr_expect(my_num == num_expect, "Ensure returns a negative number");
}

Test(atoi, integer_max) {
	const char	*str = "+2147483647";
	int	my_num = ft_atoi(str);
	int	num_expect = atoi(str);

	cr_expect(my_num == num_expect, "Ensure returns a integer max number");
}

Test(atoi, integer_min) {
	const char	*str = "-2147483648";
	int	my_num = ft_atoi(str);
	int	num_expect = atoi(str);

	cr_expect(my_num == num_expect, "Ensure returns a min integer");
}

Test(atoi, greater_integer_max) {
	const char	*str = "+2147483650";
	int	my_num = ft_atoi(str);
	int	num_expect = atoi(str);

	cr_expect(my_num == num_expect, "Ensure returns greater than the max integer");
}

Test(atoi, less_integer_min) {
	const char	*str = "-2147483650";
	int	my_num = ft_atoi(str);
	int	num_expect = atoi(str);

	cr_expect(my_num == num_expect, "Ensure returns less than the min integer");
}

Test(atoi, signal) {
	const char	*str = "127+-098";
	int	my_num = ft_atoi(str);
	int	num_expect = atoi(str);

	cr_expect(my_num == num_expect, "Ensure consecutive signal handling");
}

Test(atoi, negative_signal) {
	const char	*str = "--127098";
	int	my_num = ft_atoi(str);
	int	num_expect = atoi(str);

	cr_expect(my_num == num_expect, "Ensure consecutive negative signal handling");
}
