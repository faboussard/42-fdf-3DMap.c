#include <fcntl.h>
#include <stdio.h>
#include "../includes/libx.h"
#include "../includes/parsing.h"

int total_width(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\0')
		i++;
	return (i);
}

int total_height(int fd)
{
	int	i;

	i = 0;
	while (get_next_line(fd) != NULL)
		i++;
	return (i);
}

int map_parsing(t_map *data)
{
	int i;
	int	fd;
	const char *file_name;
	char **my_map;

	i = 0;
	file_name = "maps/42.fdf";
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(0);
	my_map = ft_split(get_next_line(fd), ' ');
	if (my_map == NULL)
		exit(EXIT_FAILURE);
	while (my_map[i])
	{
		printf("%s", my_map[i]);
		i++;
		free(my_map[i]);
	}
	data->height = total_height(fd);
	data->width = total_width(my_map[i]);
	printf("%d", data->width);
	return(0);
}

