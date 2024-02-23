
#ifndef FDF_INIT_H
#define FDF_INIT_H

#define SIZE_X 1920
#define SIZE_Y 1080

#include <stddef.h>
#include "../includes/libx.h"

typedef struct s_libx
{
	void	*mlx;
	void	*win;
}	t_libx;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_coordonates
{
	int	**x;
	int	**y;
	int	**z;
	int **destination_x;
	int **destination_y;

}	t_coordonates;

typedef struct s_map
{
	int	height;
	int	width;
	t_coordonates coordonates;
}	t_map;

typedef struct s_fdf
{
	t_map	my_map;
	t_image	my_image;
	t_libx	my_libx;
} t_fdf;

void	init(t_fdf *fdf);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);

#endif //FDF_INIT_H
