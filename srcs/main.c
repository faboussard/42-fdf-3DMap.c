#include <mlx.h>
#include "../includes/libx.h"
#include "../libft/inc/libft.h"
#include "../includes/events.h"
#include "init.h"
#include "isometric_transform.h"
#include "draw.h"
#include "error_management.h"


int	main(void)
{
//	if (argc == 2)
//	{
		t_fdf fdf;
	const char	*file_name;

	file_name = "../maps/42.fdf";
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
