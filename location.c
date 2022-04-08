#include "so_long.h"

int	abs(int x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);
}

int x_loc_left(int x)
{
	int	ret;

	if (!(x % 64))
		ret = x / 64;
	else
		ret = (x / 64) + 1;
		return (ret);
}

int	y_loc_over(int y)
{
	int	ret;

	y += 64;
	if (!(y % 64))
		ret = y / 64;
	else
		ret = (y / 64) + 1;
	return (ret);
}

int x_loc_right(int x)
{
	int	ret;

	ret = x / 64;
	return (ret);
}

int	y_loc_under(int y)
{
	int	ret;

	y += 64;
	ret = y / 64;
	return (ret);
}