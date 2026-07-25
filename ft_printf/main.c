#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		ret1;
	int		ret2;
	int		dummy;

	dummy = 5;

	printf("=== %%c ===\n");
	ret1 = ft_printf("ft: [%c]\n", 'A');
	ret2 = printf("sf: [%c]\n", 'A');
	printf("ret ft=%d sf=%d\n\n", ret1, ret2);

	printf("=== %%s ===\n");
	ret1 = ft_printf("ft: [%s]\n", "hello world");
	ret2 = printf("sf: [%s]\n", "hello world");
	printf("ret ft=%d sf=%d\n\n", ret1, ret2);

	printf("=== %%d / %%i ===\n");
	ret1 = ft_printf("ft: [%d] [%i]\n", 42, -42);
	ret2 = printf("sf: [%d] [%i]\n", 42, -42);
	printf("ret ft=%d sf=%d\n\n", ret1, ret2);

	printf("=== %%d edge cases (INT_MIN/MAX) ===\n");
	ret1 = ft_printf("ft: [%d] [%d]\n", INT_MAX, INT_MIN);
	ret2 = printf("sf: [%d] [%d]\n", INT_MAX, INT_MIN);
	printf("ret ft=%d sf=%d\n\n", ret1, ret2);

	printf("=== %%u ===\n");
	ret1 = ft_printf("ft: [%u]\n", 4294967295U);
	ret2 = printf("sf: [%u]\n", 4294967295U);
	printf("ret ft=%d sf=%d\n\n", ret1, ret2);

	printf("=== %%x / %%X ===\n");
	ret1 = ft_printf("ft: [%x] [%X]\n", 255, 255);
	ret2 = printf("sf: [%x] [%X]\n", 255, 255);
	printf("ret ft=%d sf=%d\n\n", ret1, ret2);

	printf("=== %%p ===\n");
	ret1 = ft_printf("ft: [%p]\n", (void *)&dummy);
	ret2 = printf("sf: [%p]\n", (void *)&dummy);
	printf("ret ft=%d sf=%d\n\n", ret1, ret2);

	printf("=== %%p (NULL) ===\n");
	ret1 = ft_printf("ft: [%p]\n", (void *)NULL);
	ret2 = printf("sf: [%p]\n", (void *)NULL);
	printf("ret ft=%d sf=%d\n\n", ret1, ret2);

	printf("=== %%%% ===\n");
	ret1 = ft_printf("ft: [%%]\n");
	ret2 = printf("sf: [%%]\n");
	printf("ret ft=%d sf=%d\n\n", ret1, ret2);

	printf("=== mixed / combined ===\n");
	ret1 = ft_printf("ft: %s has %d items worth $%u, hex=%x ptr=%p\n",
			"cart", 3, 150, 255, (void *)&dummy);
	ret2 = printf("sf: %s has %d items worth $%u, hex=%x ptr=%p\n",
			"cart", 3, 150, 255, (void *)&dummy);
	printf("ret ft=%d sf=%d\n\n", ret1, ret2);

	printf("=== no specifiers ===\n");
	ret1 = ft_printf("just plain text\n");
	ret2 = printf("just plain text\n");
	printf("ret ft=%d sf=%d\n\n", ret1, ret2);

    	printf("=== more formats===\n");
	ret1 = ft_printf("just %splain %\n", "text");
	// ret2 = printf("just %splain % \n", "text");
	printf("ret ft=%d sf=%d\n\n", ret1, ret2);

	return (0);
}