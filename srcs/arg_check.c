#include "so_long.h"

int	extension_check(char *filename)
{
	while (*filename)
		filename ++;
	filename --;
	if (*filename != 'r')
		return (1);
	filename --;
	if (*filename != 'e')
		return (1);
	filename --;
	if (*filename != 'b')
		return (1);
	filename --;
	if (*filename != '.')
		return (1);
	return (0);
}

void	arg_check(int argc, char *argv[], t_vars vars)
{
	if ((argc != 2) | (!vars.map))
	{
		printf("Error\nInvalid argument!\n");
		exit(0);
	}
	if (extension_check(argv[1]))
	{
		printf("Error\nInvalid extension!\n");
		free(vars.map);
		exit(0);
	}
}
