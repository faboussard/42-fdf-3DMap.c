#include <fcntl.h>
#include "../includes/libx.h"
#include "../includes/parsing.h"
#include "../includes/error_management.h"

void init_height(int fd, t_map *data)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	i = 1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		i++;
	}
	data->height = i;
}

void init_width(int fd, t_map *data)
{
	int		i;
	char 	*line;
	char**	split_lines;

	line = get_next_line(fd);
	if (line == NULL)
		error(FAILED_MALLOC);
	i = 0;
	split_lines = ft_split(line, ' ');
	if (split_lines == NULL)
		error(FAILED_MALLOC);
	while (split_lines[i] != NULL)
		i++;
	data->width = i;
}

//void init_z(int fd, t_map *data)
//{
//	int		i;
//	char**	split_lines;
//
//	while ()
//	split_lines = ft_split()
//}

void init_data(t_map *data, const char* filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error(FAILED_OPENING);
	init_width(fd, data);
	init_height(fd, data);
	init_z(fd, data);
	close(fd);
}


int map_parsing(t_map *data)
{
	int			fd;
	const char 	*file_name;
	char		*line;
	char		**my_map;
	int			i;

	i = 0;
	file_name = "../maps/test.fdf";
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		error(FAILED_OPENING);
	init_data(data, file_name); //ajouter z, x, y
	//malloquer un double tableau de int. //stocker les coordonness dans data
	//faire un atoi de la ligne quon a split, en virant lantislash
	//penser a free le split (dans init aussi)
	close(fd);
}