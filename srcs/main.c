#include <mlx.h>
#include "events.h"
#include "init.h"
#include "isometric_projection.h"
#include "draw.h"
#include "error_management.h"


void read_and_validate_file(int fd)
{
	char c;
	while (read(fd, &c, 1) > 0)
	{
		if (!(c == ' ' || (c >= '0' && c <= '9') || c == '\n'))
		{
			close(fd);
			ft_putstr_fd("data to parse is not a number. Exit.\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	close(fd);
}

int main()
//int main(int argc, char **argv)
{
	t_fdf fdf;
	int fd;
	const char *file_name;

	file_name = "../maps/basictest.fdf";
	fd = open(file_name, O_RDONLY);
	read_and_validate_file(fd);
	ft_bzero(&fdf, sizeof(fdf));
	init_resize(&fdf);

//	file_name = argv[1];
//	if (argc != 2 || fd < 0)
//		raise_error(WRONG_ARGS, &fdf);
	init_window(&fdf);
	ft_hook(&fdf);
	mlx_hook(fdf.my_libx.win, 17, 0, close_hook, &fdf);
	init_data(&fdf, file_name);
	isometric_projection(&fdf);
	create_lines(&fdf);
	mlx_loop(fdf.my_libx.mlx);
	exit(EXIT_SUCCESS);
}
