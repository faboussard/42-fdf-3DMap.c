#include <fcntl.h>
#include <stdio.h>
#include "../includes/libx.h"
#include "../includes/init.h"
#include "../includes/error_management.h"

void parse_map(int fd, t_map *data)
{
	int	i;
	int	j;
	char **split_lines;
	char *line;

	i = 0;
	data->coordonates.z = malloc(data->height * sizeof(int *));
	if (data->coordonates.z  == NULL)
		ft_error(FAILED_MALLOC, data);;
	while (i < data->height)
	{
		data->coordonates.z[i] = malloc(sizeof(int) * data->width);
		if (data->coordonates.z[i] == NULL)
			ft_error(FAILED_MALLOC, data);
		line = (get_next_line(fd));
		if (line == NULL)
			ft_error(FAILED_MALLOC, data);
		split_lines = ft_split(line, ' ');
		free(line);
		if (split_lines == NULL)
			ft_error(FAILED_MALLOC, data);
		j = 0;
		while (j < data->width)
		{
			if (split_lines[j] == NULL)
			{
				free(split_lines);
				ft_error(WRONG_MAP, data);
			}
			data->coordonates.z[i][j] = ft_atoi(split_lines[j]);
			free(split_lines[j]);
			j++;
		}
		free(split_lines);
		i++;
	}
}

void init_height(int fd, t_map *data)
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
	data->height = i;
}

void init_width(int fd, t_map *data)
{
	int i;
	char *line;
	char **split_lines;

	line = get_next_line(fd);
	if (line == NULL)
		ft_error(FAILED_MALLOC, data);
	i = 0;
	split_lines = ft_split(line, ' ');
	free(line);
	if (split_lines == NULL)
		ft_error(FAILED_MALLOC, data);
	while (split_lines[i] != NULL)
	{
		free(split_lines[i]);
		i++;
	}
	data->width = i;
	free(split_lines);
}

void init_coordonates(t_map *data)
{
	int i;
	int j;

	i = 0;
	data->coordonates.x = malloc(data->width * sizeof(int *));
	data->coordonates.y = malloc(data->width * sizeof(int *));
	if (data->coordonates.x == NULL || data->coordonates.y == NULL)
		ft_error(FAILED_MALLOC, data);
	while (i < data->width)
	{
		j = 0;
		data->coordonates.y[i] = malloc(sizeof(int) * data->height);
		data->coordonates.x[i] = malloc(sizeof(int) * data->height);
		if (data->coordonates.x[i] == NULL || data->coordonates.y[i] == NULL)
			ft_error(FAILED_MALLOC, data);
		while (j < data->height)
		{
			data->coordonates.y[i][j] = j;
			data->coordonates.x[i][j] = i;
			j++;
		}
		i++;
	}
}

//// Affichage des coordonnées y
//void print_y_coordinates(t_map *data)
//{
//	printf("Y Coordinates:\n");
//	for (int i = 0; i < data->width; i++)
//	{
//		for (int j = 0; j < data->height; j++)
//		{
//			printf("%d ", data->coordonates.y[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void print_x_coordinates(t_map *data)
//{
//	printf("X Coordinates:\n");
//	for (int i = 0; i < data->width; i++)
//	{
//		for (int j = 0; j < data->height; j++)
//		{
//			printf("%d ", data->coordonates.x[i][j]);
//		}
//		printf("\n");
//	}
//}

void init_data(t_map *data, const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error(FAILED_OPENING, data);
	init_width(fd, data);
	init_height(fd, data);
	init_coordonates(data);
//	print_x_coordinates(data);
//	print_y_coordinates(data);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error(FAILED_OPENING, data);
	parse_map(fd, data);
	close(fd);
}


int map_parsing(t_map *data)
{
	const char *file_name;

	file_name = "../maps/test.fdf";
	init_data(data, file_name);
}