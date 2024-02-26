#include "../includes/isometric_transform.h"
#include "libx.h"
#include "error_management.h"
#include <math.h>
#include "events.h"

#include <stdio.h> // A SUPPRIMER

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


void draw_line(t_fdf *fdf, int x1, int y1, int x2, int y2)
{
	int	i;
	int step;
	float dx;
	float dy;

	dx = fabs(x2 - x1);
	dy = fabs(y2 - y1);
	if(dx >= dy)
		step = dx;
	else
		step = dy;

	dx = dx / step;
	dy = dy / step;
	i = 1;
	while( i <= step)
	{
		x1 = x1 + dx;
		y1 = y1 + dy;
		my_mlx_pixel_put(fdf, x1 , y1, 0x00FF0000);
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
				draw_line(fdf, fdf->my_map.coordonates.destination_x[i][j], fdf->my_map.coordonates.destination_y[i][j],
						  fdf->my_map.coordonates.destination_x[i][j + 1], fdf->my_map.coordonates.destination_y[i][j + 1]);
			}
			j++;
		}
		i++;
	}
	if (!mlx_put_image_to_window(fdf->my_libx.mlx, fdf->my_libx.win, fdf->my_image.img, 0, 0))
		ft_error(NO_IMAGE, fdf);
}


void isometric_projection(t_fdf *fdf)
{
	int i;
	int j;
	double angle_radians;

	angle_radians = 120 * M_PI / 180;
	i = 0;
	fdf->my_map.coordonates.destination_x = malloc(fdf->my_map.height * sizeof(int *));
	fdf->my_map.coordonates.destination_y = malloc(fdf->my_map.height * sizeof(int *));
	if (fdf->my_map.coordonates.destination_x == NULL || fdf->my_map.coordonates.destination_y == NULL)
		ft_error(FAILED_MALLOC, fdf);
	while (i < fdf->my_map.height)
	{
		j = 0;
		fdf->my_map.coordonates.destination_y[i] = malloc(sizeof(int) * fdf->my_map.width);
		fdf->my_map.coordonates.destination_x[i] = malloc(sizeof(int) * fdf->my_map.width);
		if (fdf->my_map.coordonates.destination_x[i] == NULL || fdf->my_map.coordonates.destination_y[i] == NULL)
			ft_error(FAILED_MALLOC, fdf);
		while (j < fdf->my_map.width)
		{
			fdf->my_map.coordonates.destination_x[i][j] = (int)(fdf->my_map.coordonates.x[i][j] - fdf->my_map.coordonates.y[i][j] +
																 fdf->my_map.coordonates.z[i][j] * cos(angle_radians - 2));
			fdf->my_map.coordonates.destination_y[i][j] = (int)(fdf->my_map.coordonates.x[i][j] * sin(angle_radians) + fdf->my_map.coordonates.y[i][j] * sin(angle_radians + 2) +
																  fdf->my_map.coordonates.z[i][j] * sin(angle_radians - 2));
			j++;
		}
		i++;
	}
	print_dest_coordinates(fdf);
	create_lines(fdf);
}

