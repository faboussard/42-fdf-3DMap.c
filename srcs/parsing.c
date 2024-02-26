#include <fcntl.h>
#include <stdio.h>
#include "../includes/libx.h"
#include "../includes/init.h"
#include "../includes/error_management.h"

void print_coordinates(t_fdf *fdf)
{
	printf("destination Coordinates:\n");
	for (int i = 0; i < fdf->my_map.height; i++)
	{
		for (int j = 0; j < fdf->my_map.width; j++)
		{
			printf("x = %d ", fdf->my_map.coordonates.x[i][j]);
			printf("y = %d ", fdf->my_map.coordonates.y[i][j]);
			printf("z = %d ", fdf->my_map.coordonates.z[i][j]);
			printf("\n");
		}
		printf("\n");
	}
}

void parse_map(int fd, t_fdf *fdf)
{
	int	i;
	int	j;
	char **split_lines;
	char *line;

	i = 0;
	fdf->my_map.coordonates.z = malloc(fdf->my_map.height * sizeof(int *));
	if (fdf->my_map.coordonates.z  == NULL)
		raise_error(FAILED_MALLOC, fdf);;
	while (i < fdf->my_map.height)
	{
		fdf->my_map.coordonates.z[i] = malloc(sizeof(int) * fdf->my_map.width);
		if (fdf->my_map.coordonates.z[i] == NULL)
			raise_error(FAILED_MALLOC, fdf);
		line = (get_next_line(fd));
		if (line == NULL)
			raise_error(FAILED_MALLOC, fdf);
		split_lines = ft_split(line, ' ');
		free(line);
		if (split_lines == NULL)
			raise_error(FAILED_MALLOC, fdf);
		j = 0;
		while (j < fdf->my_map.width)
		{
			if (split_lines[j] == NULL)
			{
				free(split_lines);
				raise_error(WRONG_MAP, fdf);
			}
			fdf->my_map.coordonates.z[i][j] = ft_atoi(split_lines[j]);
			free(split_lines[j]);
			j++;
		}
		free(split_lines);
		i++;
	}
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
	fdf->my_map.coordonates.x = malloc(fdf->my_map.height * sizeof(int *));
	fdf->my_map.coordonates.y = malloc(fdf->my_map.height * sizeof(int *));
	if (fdf->my_map.coordonates.x == NULL || fdf->my_map.coordonates.y == NULL)
		raise_error(FAILED_MALLOC, fdf);
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

void map_parsing(t_fdf *fdf)
{
	const char	*file_name;

	file_name = "../maps/42.fdf";
	init_data(fdf, file_name);
}