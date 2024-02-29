#include <mlx.h>
#include "../libft/inc/libft.h"
#include "../includes/events.h"
#include "init.h"
#include "isometric_projection.h"
#include "draw.h"
#include "error_management.h"


int	main(void)
{
	t_fdf	fdf;

//	if (argc != 2 || open(fd, )<0)
	//raise_error(WRONG_ARGS, &fdf);

	const char	*file_name;
	file_name = "../maps/pnp_flat.fdf";

		ft_bzero(&fdf, sizeof(fdf));
		init_window(&fdf);
		ft_hook(&fdf);
		mlx_hook(fdf.my_libx.win, 17, 0, close_hook, &fdf);
		init_data(&fdf, file_name);
		isometric_projection(&fdf);
		create_lines(&fdf);
		mlx_loop(fdf.my_libx.mlx);
//	}
//	else
//		ft_putendl_fd("Please add param : ./fdf *.fdf", 1);
//	exit(EXIT_FAILURE);
	return (0);
}
