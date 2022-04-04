#include <criterion/criterion.h>

Test(atoi, simple) {
	int	num;

	num = 5;
	cr_expect(num == 5, "Tester OK!!");
}
