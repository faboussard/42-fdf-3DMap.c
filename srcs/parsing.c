#include <fcntl.h>
#include <stdio.h>
#include "../includes/libx.h"
#include "../includes/parsing.h"


void init_data(t_map *data, const char* filename)
{
	int	i,j;
	int fd;

	i = 0;
	j = 0;

	fd = open(filename, O_RDONLY);

	char *line = get_next_line(fd);
	if (line != NULL)
	{
		char** split_line = ft_split(line, ' ');
		while(split_line[j] != NULL)
			j++;
	}
	data->width = j;
	while (line != NULL)
	{
		line = get_next_line(fd);
		i++;
	}
	data->height = i;
	close(fd);
}


int map_parsing(t_map *data)
{
	int fd;
	const char *file_name;
	char *line;
	char **my_map;
	int i;

	i = 0;
	file_name = "/home/juba/fdf/maps/test.fdf";
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	init_data(data, file_name);
	//malloquer un double tableau de int.
	//faire un atoi de la ligne quon a split, en virant lantislash
	//penser a free le split (dans init aussi)
	my_map = malloc(sizeof(char*) * data->height);
	while ((line = get_next_line(fd)) != NULL)
	{
		my_map = ft_split(line, ' ');
		if (my_map[i] == NULL)
		{
			perror("Error splitting line");
			exit(EXIT_FAILURE);
		}
		i++;
		free(line);
	}
}