#include "../includes/init.h"
#include "parsing.h"
#include "error_management.h"

void init_window(t_fdf *fdf)
{
	ft_bzero(fdf, sizeof(*fdf));
	fdf->my_libx.mlx = mlx_init();
	if (fdf->my_libx.mlx == NULL)
		exit(EXIT_FAILURE);
	fdf->my_libx.win = mlx_new_window(fdf->my_libx.mlx, SIZE_X, SIZE_Y, "Fafa Fdf");
	if (fdf->my_libx.win == NULL)
		exit(EXIT_FAILURE);
	fdf->my_image.img = mlx_new_image(fdf->my_libx.mlx, 1920, 1080);
	if (fdf->my_image.img == NULL)
		exit(EXIT_FAILURE);
	fdf->my_image.addr = mlx_get_data_addr(fdf->my_image.img, &fdf->my_image.bits_per_pixel, &fdf->my_image.line_length,
								 &fdf->my_image.endian);
}

void init_data(t_fdf *fdf, const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		raise_error(FAILED_OPENING, fdf);
	init_width(fd, fdf);
	init_height(fd, fdf);
	init_coordonates(fdf);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		raise_error(FAILED_OPENING, fdf);
	parse_map(fd, fdf);
	close(fd);
}

void init_height(int fd, t_fdf *fdf)
{
	int i;
	char *line;

	line = get_next_line(fd);
	i = 1;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	fdf->my_map.height = i;
}

void init_width(int fd, t_fdf *fdf)
{
	int i;
	char *line;
	char **split_lines;

	line = get_next_line(fd);
	if (line == NULL)
		raise_error(FAILED_MALLOC, fdf);
	i = 0;
	split_lines = ft_split(line, ' ');
	free(line);
	if (split_lines == NULL)
		raise_error(FAILED_MALLOC, fdf);
	while (split_lines[i] != NULL)
	{
		free(split_lines[i]);
		i++;
	}
	fdf->my_map.width = i;
	free(split_lines);
}

void init_coordonates(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	allocate_arrays(fdf, &fdf->my_map.coordonates.x);
	allocate_arrays(fdf, &fdf->my_map.coordonates.y);
	while (i < fdf->my_map.height)
	{
		j = 0;
		fdf->my_map.coordonates.x[i] = malloc(sizeof(int) * fdf->my_map.width);
		fdf->my_map.coordonates.y[i] = malloc(sizeof(int) * fdf->my_map.width);
		if (fdf->my_map.coordonates.x[i] == NULL || fdf->my_map.coordonates.y[i] == NULL)
			raise_error(FAILED_MALLOC, fdf);
		while (j < fdf->my_map.width)
		{
			fdf->my_map.coordonates.y[i][j] = j;
			fdf->my_map.coordonates.x[i][j] = i;
			j++;
		}
		i++;
	}
}