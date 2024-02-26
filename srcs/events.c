#include "libx.h"
#include "../includes/events.h"
#include "../includes/error_management.h"
#include <X11/keysym.h>

int key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(fdf->my_libx.mlx, fdf->my_libx.win);
		mlx_destroy_display(fdf->my_libx.mlx);
		free_all(fdf);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_hook(t_fdf *fdf)
{
	mlx_destroy_window(fdf->my_libx.mlx, fdf->my_libx.win);
	mlx_destroy_display(fdf->my_libx.mlx);
	free_all(fdf);
	exit(EXIT_SUCCESS);
}

void ft_hook(t_fdf *fdf)
{
	mlx_hook(fdf->my_libx.win, ON_KEYDOWN, KEY_PRESS, key_hook, fdf);
}
