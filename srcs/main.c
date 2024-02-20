#include <mlx.h>
#include "../includes/libx.h"
#include <stdlib.h>
#include "../libft/inc/libft.h"
#include "../includes/init.h"
#include "../includes/events.h"
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

	//bouger dans le init, et continuer le init apres avoir fait le parsing
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, SIZE_X, SIZE_Y, "Fafa Fdf");
	//parsing
	//events
	ft_hook(&fdf);
	mlx_hook(fdf.win, 17, 0, close_hook, &fdf);
	map_parsing(&data);
	//fermeture

	mlx_loop(fdf.mlx);
	return (0);
}
