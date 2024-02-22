
#ifndef FDF_PARSING_H
#define FDF_PARSING_H

typedef struct s_coordonates
{
	int	**x;
	int	**y;
	int	**z;
}	t_coordonates;

typedef struct s_map
{
	int	height;
	int	width;
	t_coordonates coordonates;
}	t_map;

/*pour carte test
 * x :
0 1 2 3 4 5 6 7
0 1 2 3 4 5 6 7
0 1 2 3 4 5 6 7
0 1 2 3 4 5 6 7

 y :
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1
2 2 2 2 2 2 2 2
3 3 3 3 3 3 3 3

 */
int map_parsing(t_map *data);

#endif //FDF_PARSING_H
