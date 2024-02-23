
#ifndef FDF_INIT_H
#define FDF_INIT_H

#define SIZE_X 1920
#define SIZE_Y 1080

#include <stddef.h>
#include "../includes/libx.h"

typedef struct s_coordonates
{
	int	**x;
	int	**y;
	int	**z;
	double **destination_x;
	double **destination_y;

}	t_coordonates;

typedef struct s_map
{
	int	height;
	int	width;
	t_coordonates coordonates;
}	t_map;

typedef struct s_fdf
{
	t_libx	display;
	t_map	my_map;
} t_fdf;

void init_map(t_map *data);

#endif //FDF_INIT_H
