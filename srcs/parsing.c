#include <fcntl.h>
#include "../includes/libx.h"
#include "../includes/init.h"
#include "../includes/error_management.h"

void allocate_arrays(t_fdf *fdf, int ***coordonates)
{
	*coordonates = malloc(fdf->my_map.height * sizeof(int *));
	if (*coordonates == NULL)
		raise_error(FAILED_MALLOC, fdf);
}

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
	allocate_arrays(fdf, &fdf->my_map.coordonates.z);
	while (i < fdf->my_map.height)
	{
		fdf->my_map.coordonates.z[i] = malloc(sizeof(int) * fdf->my_map.width);
		if (fdf->my_map.coordonates.z[i] == NULL)
			raise_error(FAILED_MALLOC, fdf);
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



