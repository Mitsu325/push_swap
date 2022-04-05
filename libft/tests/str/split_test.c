#include <criterion/criterion.h>
#include "../../includes/libft.h"
#include <stdio.h>

char	*str = NULL;
char	char_split = ' ';
char	**result = NULL;

void	suitesetup(void)
{
	str = "Hey MarVin!";
	return ;
}

TestSuite(split, .init=suitesetup);

Test(split, create) {
	int	i;
	result = ft_split(str, char_split);
	cr_assert(result, "Ensure split string with space, index = 0");
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

Test(split, str_null) {
	str = "\0";
	result = ft_split(str, char_split);
	cr_assert(result, "Ensure returns NULL if string is empty");
}
