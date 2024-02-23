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
//	if (argc == 2)
//	{
		t_fdf fdf;

		init(&fdf);
		//mlx_initimage - si ca reussit faire getddr

		//connecter les points entre eux avec des vecteurs (bresenhem)
		//faire putpixel
		//fonction save qui garde letat actuel pour revenir dessus ( bonus)
		ft_hook(&fdf);
		mlx_hook(fdf.my_libx.win, 17, 0, close_hook, &fdf);
		map_parsing(&fdf);
	isometric_projection(&fdf);
		mlx_loop(fdf.my_libx.mlx);
//	}
//	else
//		ft_putendl_fd("Please add param : ./fdf *.fdf", 1);
//	exit(EXIT_FAILURE);
	return (0);
}
