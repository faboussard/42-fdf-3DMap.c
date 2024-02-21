
#ifndef FDF_PARSING_H
#define FDF_PARSING_H

typedef struct s_map
{
	int	height;
	int	width;
	int	x;
	int	z;
	int	y;
}	t_map;

int map_parsing(t_map *data);

#endif //FDF_PARSING_H
