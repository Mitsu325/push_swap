#include <criterion/criterion.h>
#include "../../includes/libft.h"
#include <stdio.h>

int		num = 0;
char	*result = NULL;
char	*expect = NULL;

Test(itoa, positive_num) {
	num = 127;
	result = ft_itoa(num);
	expect = "127";
	cr_expect_str_eq(result, expect,
	"Ensure returns a positive number in string format");
	free(result);
}

Test(itoa, negative_num) {
	num = -127;
	result = ft_itoa(num);
	expect = "-127";
	cr_expect_str_eq(result, expect,
	"Ensure returns a negative number in string format");
}

Test(itoa, integer_max) {
	num = 2147483647;
	result = ft_itoa(num);
	expect = "2147483647";
	cr_expect_str_eq(result, expect,
	"Ensure returns a integer max number in string format");
}

Test(itoa, integer_min) {
	num = -2147483648;
	result = ft_itoa(num);
	expect = "-2147483648";
	cr_expect_str_eq(result, expect,
	"Ensure returns a integer min number in string format");
}

Test(itoa, signal) {
	num = +123;
	result = ft_itoa(num);
	expect = "123";
	cr_expect_str_eq(result, expect,
	"Ensure returns positive number without signal in string format");
}
