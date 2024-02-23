#include "../includes/isometric_transform.h"
#include "libx.h"
#include "error_management.h"
#include <math.h>

#include <stdio.h> // A SUPPRIMER

void print_z_coordinates(t_map *data)
{
	printf("Z Coordinates:\n");
	for (int i = 0; i < data->height; i++)
	{
		for (int j = 0; j < data->width; j++)
		{
			printf("%f ", data->coordonates.destination_x[i][j]);
		}
		printf("\n");
	}
}

void print_y_coordinates_dest(t_map *data)
{
	printf("Y Coordinates:\n");
	for (int i = 0; i < data->height; i++)
	{
		for (int j = 0; j < data->width; j++)
		{
			printf("%f ", data->coordonates.destination_y[i][j]);
		}
		printf("\n");
	}
}

void print_x_coordinates_dest(t_map *data)
{
	printf("X Coordinates:\n");
	for (int i = 0; i < data->height; i++)
	{
		for (int j = 0; j < data->width; j++)
		{
			printf("%f ", data->coordonates.destination_x[i][j]);
		}
		printf("\n");
	}
}

double angle_radians = 120 * M_PI / 180;

void isometric_data(t_map *data)
{
	int i;
	int j;

	i = 0;
	data->coordonates.destination_x = malloc(data->height * sizeof(int *));
	data->coordonates.destination_y = malloc(data->height * sizeof(int *));
	if (data->coordonates.destination_x == NULL || data->coordonates.destination_y == NULL)
		ft_error(FAILED_MALLOC, data);
	while (i < data->height)
	{
		j = 0;
		data->coordonates.destination_y[i] = malloc(sizeof(int) * data->width);
		data->coordonates.destination_x[i] = malloc(sizeof(int) * data->width);
		if (data->coordonates.destination_x[i] == NULL || data->coordonates.destination_y[i] == NULL)
			ft_error(FAILED_MALLOC, data);
		while (j < data->width)
		{
			data->coordonates.destination_x[i][j] =
					(data->coordonates.x[i][j] * cos(angle_radians) + data->coordonates.y[i][j] * cos(angle_radians) +
					data->coordonates.z[i][j] * cos(angle_radians));
			data->coordonates.destination_y[i][j] =
					(data->coordonates.x[i][j] * sin(angle_radians) + data->coordonates.y[i][j] * sin(angle_radians) +
					data->coordonates.z[i][j] * sin(angle_radians));
			j++;
		}
		i++;
	}
	free(data->coordonates.x);
	free(data->coordonates.y);
	free(data->coordonates.z);
	print_x_coordinates_dest(data);
	print_y_coordinates_dest(data);
}

