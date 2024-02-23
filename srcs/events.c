#include "libx.h"
#include "../includes/events.h"
#include "../includes/error_management.h"

int key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fdf->display.mlx, fdf->display.win);
//		exit(0);
		quit(fdf);
	}
	return 0;
}

int	close_hook(t_fdf *fdf)
{
	mlx_destroy_window(fdf->display.mlx, fdf->display.win);
//	exit(0);
	quit(fdf);
}

void ft_hook(t_fdf *fdf)
{
	mlx_hook(fdf->display.win, ON_KEYDOWN, KEY_PRESS, key_hook, fdf);
}

int quit(t_fdf *fdf)
{
	free_all(fdf);
	exit(0);
}