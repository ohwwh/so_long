#include "mlx.h"

int	main(void)
{
	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window(mlx_ptr, 500, 500, "New");
	mlx_loop(mlx_ptr);
	return (0);
}
