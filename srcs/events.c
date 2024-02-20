#include "libx.h"
#include "../includes/events.h"

int key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	return 0;
}

int	close_hook(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

void ft_hook(t_fdf *fdf)
{
	mlx_hook(fdf->win, ON_KEYDOWN, KEY_PRESS, key_hook, fdf);
}