#include <criterion/criterion.h>

Test(create, simple) {
	int	num;

	num = 5;
	cr_expect(num != 0, "Tester OK!!");
}
