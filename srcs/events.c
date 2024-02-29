#include "mlx.h"
#include "events.h"
#include "error_management.h"
#include <X11/keysym.h>
#include "init.h"

int key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Escape)
	{
		free_all(fdf);
		exit(EXIT_SUCCESS);
	}
	if (keycode == XK_KP_Space)
	{
		fdf->my_map.resize_factor_x --;
		fdf->my_map.resize_factor_y --;
	}
	if (keycode == XK_KP_Enter)
	{
		fdf->my_map.resize_factor_x --;
		fdf->my_map.resize_factor_y--;
	}
	return (0);
}

int	close_hook(t_fdf *fdf)
{
	free_all(fdf);
	exit(EXIT_SUCCESS);
}

void ft_hook(t_fdf *fdf)
{
	mlx_hook(fdf->my_libx.win, ON_KEYDOWN, KEY_PRESS, key_hook, fdf);
}
