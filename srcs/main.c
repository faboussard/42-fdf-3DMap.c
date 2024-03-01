#include <mlx.h>
#include "events.h"
#include "init.h"
#include "isometric_projection.h"
#include "draw.h"
#include "error_management.h"

int main(int argc, char **argv)
{
	t_fdf fdf;
	const char *file_name;

	ft_bzero(&fdf, sizeof(fdf));
	init_resize(&fdf);
	file_name = argv[1];
	if (argc != 2 || open(file_name, O_RDONLY) < 0)
		raise_error(WRONG_ARGS, &fdf, 0);
	init_window(&fdf);
	ft_hook(&fdf);
	mlx_hook(fdf.my_libx.win, 17, 0, close_hook, &fdf);
	init_data(&fdf, file_name);
	isometric_projection(&fdf);
	create_lines(&fdf);
	mlx_loop(fdf.my_libx.mlx);
	exit(EXIT_SUCCESS);
}
