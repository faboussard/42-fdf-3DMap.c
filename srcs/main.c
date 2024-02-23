#include <mlx.h>
#include "../includes/libx.h"
#include <stdlib.h>
#include "../libft/inc/libft.h"
#include "../includes/init.h"
#include "../includes/events.h"
#include "init.h"
#include "isometric_transform.h"
#include "parsing.h"


int	main(void)
{
	t_fdf fdf;

	init(&fdf);
	map_parsing(&fdf);
	isometric_data(&fdf);
	//mlx_initimage - si ca reussit faire getddr

	//connecter les points entre eux avec des vecteurs (bresenhem)
	//faire putpixel
	//fonction save qui garde letat actuel pour revenir dessus ( bonus)
//	ft_hook(&fdf);

	mlx_hook(fdf.my_libx.win, 17, 0, close_hook, &fdf);
	my_mlx_pixel_put(&fdf, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(fdf.my_libx.mlx, fdf.my_libx.win, fdf.my_image.img, 0, 0);

	mlx_loop(fdf.my_libx.mlx);
	return (0);
}
