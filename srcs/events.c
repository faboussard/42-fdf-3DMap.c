#include "libx.h"
#include "../includes/events.h"
#include "../includes/error_management.h"

int key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fdf->my_libx.mlx, fdf->my_libx.win);
		quit(fdf);
	}
	exit(EXIT_SUCCESS);
}

int	close_hook(t_fdf *fdf)
{
	mlx_destroy_window(fdf->my_libx.mlx, fdf->my_libx.win);
	quit(fdf);
	exit(EXIT_SUCCESS);
}

void ft_hook(t_fdf *fdf)
{
	mlx_hook(fdf->my_libx.win, ON_KEYDOWN, KEY_PRESS, key_hook, fdf);
}

int quit(t_fdf *fdf)
{
	free_all(fdf);
//	free(fdf);
	exit(EXIT_SUCCESS);
}