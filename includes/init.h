
#ifndef FDF_INIT_H
#define FDF_INIT_H

#define SIZE_X 1920
#define SIZE_Y 1080
#define WIDTH SIZE_X / 2
#define HEIGHT SIZE_Y / 2

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
	float **destination_x;
	float **destination_y;

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

void	init_window(t_fdf *fdf);
void	init_data(t_fdf *fdf, const char *filename);
void allocate_arrays(t_fdf *fdf, int ***coordonates);

#endif //FDF_INIT_H
