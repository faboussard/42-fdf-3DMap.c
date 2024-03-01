#include "init.h"
#include "error_management.h"

void init_height(int fd, t_fdf *fdf)
{
	int i;
	char *line;

	line = get_next_line(fd);
	i = 1;
	while (line != NULL && line[0] != '\n' )
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (line)
		free(line);
	fdf->my_map.height = i;
}

void init_width(int fd, t_fdf *fdf)
{
	int		i;
	char	*line;
	char	**split_lines;

	line = get_next_line(fd);
	if (line == NULL)
		raise_error(FAILED_MALLOC, fdf, &fd);
	i = 0;
	split_lines = ft_split(line, ' ');
	if (split_lines == NULL)
	{
		free(line);
		raise_error(FAILED_MALLOC, fdf, &fd);
	}
	free(line);
	while (split_lines[i] != NULL)
		i++;
	ft_free_strs_array(split_lines, i);
	fdf->my_map.width = i;
}

char **parse_line(int fd, t_fdf *fdf)
{
	char **split_lines;
	char *line;

	line = get_next_line(fd);
	if (line == NULL)
		raise_error(FAILED_MALLOC, fdf, &fd);
	split_lines = ft_split(line, ' ');
	if (split_lines == NULL)
	{
		free(line);
		raise_error(FAILED_MALLOC, fdf, &fd);
	}
	free(line);
	return (split_lines);
}

void parse_map(int fd, t_fdf *fdf)
{
	int		i;
	int		j;
	char	**split_lines;

	i = 0;
	allocate_arrays(fdf, (int **) &fdf->my_map.coordonates.z, fdf->my_map.height);
	while (i < fdf->my_map.height)
	{
		allocate_arrays(fdf, &fdf->my_map.coordonates.z[i], fdf->my_map.width);
		split_lines = parse_line(fd, fdf);
		j = 0;
		while (j < fdf->my_map.width)
		{
			if (!ft_isdigit(*split_lines[j]))
			{
				ft_free_strs_array(split_lines, j);
				raise_error(WRONG_DATA_IN_MAP, fdf, &fd);
			}
			fdf->my_map.coordonates.z[i][j] = ft_atoi(split_lines[j]);
			j++;
		}
		ft_free_strs_array(split_lines, j);
		i++;
	}
	//on doit librer splitline de lauter fonction aussi. et on doit iben liberer tout splitline.
	//pb si plein despaces a la fin et que ya un m cest ignore.  verifier la height. em fait il devrait quit direct en disant qu c pas la bonne taille.
	ft_free_strs_array(split_lines, j);
}

void init_data(t_fdf *fdf, const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		raise_error(FAILED_OPENING, fdf, 0);
	fdf->my_map.resize_factor_x = 20;
	fdf->my_map.resize_factor_y = 20;
	init_width(fd, fdf);
	init_height(fd, fdf);
	init_coordonates(fdf);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		raise_error(FAILED_OPENING, fdf, 0);
	parse_map(fd, fdf);
	close(fd);
}



