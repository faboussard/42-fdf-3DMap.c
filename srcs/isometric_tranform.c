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
		fdf->my_map.coordonates.destination_y[i] = malloc(sizeof(double) * fdf->my_map.width);
		fdf->my_map.coordonates.destination_x[i] = malloc(sizeof(double) * fdf->my_map.width);
		if (fdf->my_map.coordonates.destination_x[i] == NULL || fdf->my_map.coordonates.destination_y[i] == NULL)
			ft_error(FAILED_MALLOC, fdf);
		while (j < fdf->my_map.width)
		{
			fdf->my_map.coordonates.destination_x[i][j] =
					(fdf->my_map.coordonates.x[i][j] * cos(angle_radians) + fdf->my_map.coordonates.y[i][j] * cos(angle_radians) +
					fdf->my_map.coordonates.z[i][j] * cos(angle_radians));
			fdf->my_map.coordonates.destination_y[i][j] =
					(fdf->my_map.coordonates.x[i][j] * sin(angle_radians) + fdf->my_map.coordonates.y[i][j] * sin(angle_radians) +
					fdf->my_map.coordonates.z[i][j] * sin(angle_radians));
			j++;
		}
		i++;
	}
//	print_x_coordinates_dest(data);
//	print_y_coordinates_dest(data);
}

