#include "isometric_projection.h"
#include "mlx.h"
#include <math.h>

void my_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;
	int		offset_x;
	int		offset_y;

	offset_x = x * (fdf->my_image.bits_per_pixel / 8) ;
	offset_y = y * fdf->my_image.line_length;
	if (x >= 0 && x < WIDTH_DISPLAY && y >= 0 && y < HEIGHT_DISPLAY)
	{
		dst = fdf->my_image.addr + abs(offset_x + offset_y);
		*(unsigned int *) dst = color;
	}
}

void draw_line(t_fdf *fdf, float x1, float y1, float x2, float y2)
{
	float	step;
	float	dx;
	float	dy;

	dx = x2 - x1;
	dy = y2 - y1;
	if (fabsf(dx) >= fabsf(dy))
		step = fabsf(dx);
	else
		step = fabsf(dy);
	dx /= step;
	dy /= step;
	while (step-- > 0)
	{
		x1 += dx;
		y1 += dy;
		my_pixel_put(fdf, x1 + WIDTH_DISPLAY / 2, y1 + HEIGHT_DISPLAY / 3, 0x00FF0000);
	}
}

void draw_y(t_fdf *fdf, int i, int resize)
{
	int j;

	j = 0;

	while (j < fdf->my_map.height - 1)
	{
		draw_line(fdf, fdf->my_map.coordonates.destination_x[j][i]  * resize,
				  fdf->my_map.coordonates.destination_y[j][i] * resize,
				  fdf->my_map.coordonates.destination_x[j + 1][i] *resize,
				  fdf->my_map.coordonates.destination_y[j + 1][i] * resize);
		j++;
	}
}

void draw_x(t_fdf *fdf, int i, int resize)
{
	int j;

	j = 0;
	while (j < fdf->my_map.width - 1)
	{
		draw_line(fdf, fdf->my_map.coordonates.destination_x[i][j] * resize,
				  fdf->my_map.coordonates.destination_y[i][j] * resize,
				  fdf->my_map.coordonates.destination_x[i][j + 1] * resize,
				  fdf->my_map.coordonates.destination_y[i][j + 1] * resize);
		j++;
	}
}

void create_lines(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->my_map.height)
	{
		draw_x(fdf, i, fdf->my_map.resize);
		i++;
	}
	i = 0;
	while (i < fdf->my_map.width)
	{
		draw_y(fdf, i, fdf->my_map.resize);
		i++;
	}
	mlx_put_image_to_window(fdf->my_libx.mlx, fdf->my_libx.win, fdf->my_image.img, 0, 0);
}
