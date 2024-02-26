#include "../includes/isometric_transform.h"
#include "libx.h"
#include "error_management.h"
#include <math.h>
#include "events.h"

#include <stdio.h> // A SUPPRIMER

#define WIDTH SIZE_X / 2
#define HEIGHT SIZE_Y / 2

void print_dest_coordinates(t_fdf *fdf)
{
	printf("X destination Coordinates:\n");
	for (int i = 0; i < fdf->my_map.height; i++)
	{
		for (int j = 0; j < fdf->my_map.width; j++)
		{
			printf("x = %d ", fdf->my_map.coordonates.destination_x[i][j]);
			printf("y = %d ", fdf->my_map.coordonates.destination_y[i][j]);
			printf("\n");
		}
		printf("\n");
	}
}


#include <stdio.h>
#include <math.h>

void my_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char *dst;
	int offset;
	int map_scale;

	offset = (y * fdf->my_image.line_length + x * (fdf->my_image.bits_per_pixel / 8));
//	map_scale = abs()
	//ajouter le scale a y et x
	dst = fdf->my_image.addr + abs(offset);
	*(unsigned int *) dst = color; //on met le pixel a ladresse de dest
}


void draw_line(t_fdf *fdf, int x1, int y1, int x2, int y2)
{
	int i;
	int step;
	int dx;
	int dy;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	if (dx == 0 && dy == 0)
		step = 1;
	else
	{
		if (dx >= dy)
			step = dx;
		else
			step = dy;
	}
	dx = dx / step;
	dy = dy / step;
	i = 1;
	while (i <= step)
	{
		x1 = x1 + dx;
		y1 = y1 + dy;
		my_pixel_put(fdf, x1, y1, 0x00FF0000); //renvoyer les pointeures
		i++;
	}
}


void create_lines(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->my_map.height)
	{
		j = 0;
		while (j < fdf->my_map.width)
		{
			if (j + 1 < fdf->my_map.width)
			{
				draw_line(fdf, fdf->my_map.coordonates.destination_x[i][j] + WIDTH,
						  fdf->my_map.coordonates.destination_y[i][j] + HEIGHT,
						  fdf->my_map.coordonates.destination_x[i][j + 1] + WIDTH,
						  fdf->my_map.coordonates.destination_y[i][j + 1] + HEIGHT);
			}
			j++;
		}
		i++;
	}
	if (!mlx_put_image_to_window(fdf->my_libx.mlx, fdf->my_libx.win, fdf->my_image.img, 0, 0))
		raise_error(NO_IMAGE, fdf);
}

double degree_to_radian()
{
	return (((30 * M_PI) / 120));
}

void isometric_projection(t_fdf *fdf)
{
	int		i;
	int		j;
	double	radian = degree_to_radian();
	double	resize = abs(fdf->my_map.width + fdf->my_map.width - fdf->my_map.height) * sqrt(3);
	double	resize2 = (abs(fdf->my_map.height + fdf->my_map.height - fdf->my_map.width) * sqrt(3));


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
			fdf->my_map.coordonates.destination_x[i][j] = (int)(((fdf->my_map.coordonates.x[i][j] - fdf->my_map.coordonates.y[i][j]) * cos(radian))) * resize2 * -1;
			fdf->my_map.coordonates.destination_y[i][j] = (int)(((fdf->my_map.coordonates.x[i][j] + fdf->my_map.coordonates.y[i][j]) * sin(radian) -
																  fdf->my_map.coordonates.z[i][j]) * resize2);
			j++;
		}
		i++;
	}
	print_dest_coordinates(fdf);
	create_lines(fdf);
}

