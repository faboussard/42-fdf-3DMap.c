#include "../includes/isometric_transform.h"
#include "libx.h"
#include "error_management.h"
#include <math.h>
#include "events.h"

#include <stdio.h> // A SUPPRIMER

void my_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char *dst;
	int offset;

	offset = (y * fdf->my_image.line_length + x * (fdf->my_image.bits_per_pixel / 8));
	dst = fdf->my_image.addr + abs(offset);
	*(unsigned int *) dst = color;
}

void draw_line(t_fdf *fdf, float x1, float y1, float x2, float y2)
{
	float step;
	float dx;
	float dy;

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
		my_pixel_put(fdf, x1, y1, 0x00FF0000);
	}
}

void draw_y(t_fdf *fdf, int i)
{
	int j;

	j = 0;
	while (j < fdf->my_map.height - 1)
	{
		draw_line(fdf, fdf->my_map.coordonates.destination_x[j][i] + WIDTH,
				  fdf->my_map.coordonates.destination_y[j][i] + HEIGHT,
				  fdf->my_map.coordonates.destination_x[j + 1][i] + WIDTH,
				  fdf->my_map.coordonates.destination_y[j + 1][i] + HEIGHT);
		j++;
	}
}

void draw_x(t_fdf *fdf, int i)
{
	int j;

	j = 0;
	while (j < fdf->my_map.width - 1)
	{
		draw_line(fdf, fdf->my_map.coordonates.destination_x[i][j] + WIDTH,
				  fdf->my_map.coordonates.destination_y[i][j] + HEIGHT,
				  fdf->my_map.coordonates.destination_x[i][j + 1] + WIDTH,
				  fdf->my_map.coordonates.destination_y[i][j + 1] + HEIGHT);
		j++;
	}
}


void create_lines(t_fdf *fdf)
{
	int i;
	i = 0;
	while (i < fdf->my_map.height)
	{
		draw_x(fdf, i);
		i++;
	}
	i = 0;
	while (i < fdf->my_map.width)
	{
		draw_y(fdf, i);
		i++;
	}
}

double degree_to_radian()
{
	return (((20 * M_PI) / 120));
}

void isometric_projection(t_fdf *fdf)
{
	int i;
	int j;
	double radian = degree_to_radian();
	double resize = abs(fdf->my_map.width + fdf->my_map.width - fdf->my_map.height) * sqrt(3);
	double resize2 = (abs(fdf->my_map.height + fdf->my_map.height - fdf->my_map.width * sqrt(6)));


	i = 0;
	fdf->my_map.coordonates.destination_x = malloc(fdf->my_map.height * sizeof(int *));
	fdf->my_map.coordonates.destination_y = malloc(fdf->my_map.height * sizeof(int *));
	if (fdf->my_map.coordonates.destination_x == NULL || fdf->my_map.coordonates.destination_y == NULL)
		raise_error(FAILED_MALLOC, fdf);
	while (i < fdf->my_map.height)
	{
		j = 0;
		fdf->my_map.coordonates.destination_y[i] = malloc(sizeof(int) * fdf->my_map.width);
		fdf->my_map.coordonates.destination_x[i] = malloc(sizeof(int) * fdf->my_map.width);
		if (fdf->my_map.coordonates.destination_x[i] == NULL || fdf->my_map.coordonates.destination_y[i] == NULL)
			raise_error(FAILED_MALLOC, fdf);
		while (j < fdf->my_map.width)
		{
			fdf->my_map.coordonates.destination_x[i][j] = (float) (
					(fdf->my_map.coordonates.x[i][j] - ((fdf->my_map.coordonates.y[i][j]) * cos(radian))) * resize2 * -1);
			fdf->my_map.coordonates.destination_y[i][j] = (float) ((
					((fdf->my_map.coordonates.x[i][j] + fdf->my_map.coordonates.y[i][j]) * sin(radian) -
					 fdf->my_map.coordonates.z[i][j]) * resize2));
			j++;
		}
		i++;
	}
	create_lines(fdf);
	if (!mlx_put_image_to_window(fdf->my_libx.mlx, fdf->my_libx.win, fdf->my_image.img, 0, 0))
		raise_error(NO_IMAGE, fdf);
}

