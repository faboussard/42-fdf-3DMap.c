#include "init.h"
#include "error_management.h"

char **parse_line(int fd, t_fdf *fdf)
{
	char **split_lines;
	char *line;

	line = get_next_line(fd);
	if (line == NULL)
		raise_error(FAILED_MALLOC, fdf);
	split_lines = ft_split(line, ' ');
	free(line);
	if (split_lines == NULL)
		raise_error(FAILED_MALLOC, fdf);
	return (split_lines);
}

int parse_value(char *str, t_fdf *fdf)
{
	int value;

	if (str == NULL)
	{
		raise_error(WRONG_MAP, fdf);
		return (0);
	}
	value = ft_atoi(str);
	free(str);
	return (value);
}

void parse_map(int fd, t_fdf *fdf)
{
	int	i;
	int j;

	i = 0;
	allocate_arrays(fdf, (int **) &fdf->my_map.coordonates.z, fdf->my_map.height);
	while (i < fdf->my_map.height)
	{
		allocate_arrays(fdf, &fdf->my_map.coordonates.z[i], fdf->my_map.width);
		char **split_lines = parse_line(fd, fdf);
		j = 0;
		while (j < fdf->my_map.width)
		{
			fdf->my_map.coordonates.z[i][j] = parse_value(split_lines[j], fdf);
			j++;
		}
		free(split_lines);
		i++;
	}
}

void init_data(t_fdf *fdf, const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		raise_error(FAILED_OPENING, fdf);
	fdf->my_map.resize_factor_x = 20;
	fdf->my_map.resize_factor_y = 20;
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



