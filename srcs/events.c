#include "mlx.h"
#include "events.h"
#include "error_management.h"
#include <X11/keysym.h>
#include "init.h"
#include "draw.h"

int key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Escape)
	{
		free_all(fdf);
		exit(EXIT_SUCCESS);
	}
	if (keycode == XK_space)
	{
		mlx_destroy_image(fdf->my_libx.mlx, fdf->my_image.img);
		init_image(fdf);
		fdf->my_map.resize++;
		create_lines(fdf);
	}
	if (keycode == XK_Return)
	{
		mlx_destroy_image(fdf->my_libx.mlx, fdf->my_image.img);
		init_image(fdf);
		if (fdf->my_map.resize > 1)
			fdf->my_map.resize--;
		create_lines(fdf);
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
