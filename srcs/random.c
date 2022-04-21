#include "so_long.h"

int	ft_rand(void)
{
	static int	x;
	x = abs((1664525 * x + 1013904223) % (2147483647));
	return (x);
}