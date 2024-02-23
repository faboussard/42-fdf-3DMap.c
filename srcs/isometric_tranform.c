#include "../includes/isometric_transform.h"
#include "libx.h"
#include "error_management.h"
#include <math.h>

#include <stdio.h> // A SUPPRIMER

//void print_z_coordinates(t_map *data)
//{
//	printf("Z Coordinates:\n");
//	for (int i = 0; i < data->height; i++)
//	{
//		for (int j = 0; j < data->width; j++)
//		{
//			printf("%f ", data->coordonates.destination_x[i][j]);
//		}
//		printf("\n");
//	}
//}

//void print_y_coordinates_dest(t_map *data)
//{
//	printf("Y Coordinates:\n");
//	for (int i = 0; i < data->height; i++)
//	{
//		for (int j = 0; j < data->width; j++)
//		{
//			printf("%f ", data->coordonates.destination_y[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void print_x_coordinates_dest(t_map *data)
//{
//	printf("X Coordinates:\n");
//	for (int i = 0; i < data->height; i++)
//	{
//		for (int j = 0; j < data->width; j++)
//		{
//			printf("%f ", data->coordonates.destination_x[i][j]);
//		}
//		printf("\n");
//	}
//}

#include <stdio.h>
#include <math.h>


//
//void create_lines(t_fdf *fdf)
//{
//	int	i;
//	int step;
//	int dx;
//	int dy;
//
//	dx = ft_abs(fdf->my_map.coordonates.x[0][1] - fdf->my_map.coordonates.x[0][0]);
//	dy = ft_abs(fdf->my_map.coordonates.y[0][1] - fdf->my_map.coordonates.y[0][0]);
//
//	if(dx >= dy)
//		step = dx;
//	else
//		step = dy;
//
//	dx = dx / step;
//	dy = dy / step;
//
//	int x = fdf->my_map.coordonates.x[0][0];
//	int y = fdf->my_map.coordonates.y[0][0];
//
//	i = 1;
//	while( i <= step)
//	{
//		my_mlx_pixel_put(fdf, x , y, 5);
//		x[i] = x+dx;
//		y=y+dy;
//		i=i+1;
//		delay(100);
//	}
//}

double angle_radians = 120 * M_PI / 180;

void isometric_data(t_fdf *fdf)
{
	int i;
	int j;

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
			fdf->my_map.coordonates.destination_x[i][j] =(int)(fdf->my_map.coordonates.x[i][j] * cos(angle_radians) + fdf->my_map.coordonates.y[i][j] * cos(angle_radians) +
					fdf->my_map.coordonates.z[i][j] * cos(angle_radians));
			fdf->my_map.coordonates.destination_y[i][j] = (int)(fdf->my_map.coordonates.x[i][j] * sin(angle_radians) + fdf->my_map.coordonates.y[i][j] * sin(angle_radians) +
					fdf->my_map.coordonates.z[i][j] * sin(angle_radians));
			j++;
		}
		i++;
	}
//	print_x_coordinates_dest(data);
//	print_y_coordinates_dest(data);
}

