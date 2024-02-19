#include <mlx.h>
#include "../includes/libx.h"
#include <stdlib.h>
#include "../libft/inc/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	generate_checkerboard(t_data *data, int size)
{
	int width = 1920; // width of the window
	int height = 1080;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int checker_color = ((i / size) + (j / size)) % 2 == 0 ? 0xFFFFFFFF : 0xFF000000;

			my_mlx_pixel_put(data, j, i, checker_color);
		}
	}
}



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

int	main(void)
{

	t_fdf fdf;

	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 1920, 1080, "Fafa Fdf");
	mlx_hook(fdf.win, ON_KEYDOWN, KEY_PRESS, key_hook, &fdf);
	mlx_hook(fdf.win, 17, 0, close_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
