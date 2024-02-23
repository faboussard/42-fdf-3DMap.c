#include <mlx.h>
#include "../includes/libx.h"
#include <stdlib.h>
#include "../libft/inc/libft.h"
#include "../includes/init.h"
#include "../includes/events.h"
#include "init.h"
#include "isometric_transform.h"
#include "parsing.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{

	t_fdf fdf;
	t_map data;

	init_map(&data);
	fdf.display.mlx = mlx_init();
	fdf.display.win = mlx_new_window(fdf.display.mlx, SIZE_X, SIZE_Y, "Fafa Fdf");
	//events
	map_parsing(&fdf);
	isometric_data(&fdf);
	//connecter les points entre eux avec des vecteurs (bresenhem)
	//faire putpixel
	//fonction save qui garde letat actuel pour revenir dessus ( bonus)
//	ft_hook(&fdf);

	mlx_hook(fdf.display.win, 17, 0, close_hook, &fdf);

	//fermeture

	mlx_loop(fdf.display.mlx);
	return (0);
}
