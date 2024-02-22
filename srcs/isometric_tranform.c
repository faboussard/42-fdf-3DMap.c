#include "../includes/isometric_transform.h"
#include "libx.h"
#include "error_management.h"
#include <math.h>

#include <stdio.h> // A SUPPRIMER

double angle_radians = 120 * M_PI / 180;

void isometric_data(t_map *data)
{
	int i;
	int j;

	i = 0;
	data->coordonates.destination_x = malloc(data->width * sizeof(int *));
	data->coordonates.destination_y = malloc(data->width * sizeof(int *));
	if (data->coordonates.destination_x == NULL || data->coordonates.destination_y == NULL)
		ft_error(FAILED_MALLOC, data);
	while (i < data->height)
	{
		j = 0;
		data->coordonates.destination_y[i] = malloc(sizeof(int) * data->height);
		data->coordonates.destination_x[i] = malloc(sizeof(int) * data->height);
		if (data->coordonates.destination_x[i] == NULL || data->coordonates.y[i] == NULL)
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
}

// Affichage des coordonnées y
void print_y_coordinates(t_map *data)
{
	printf("Y Coordinates:\n");
	for (int i = 0; i < data->width; i++)
	{
		for (int j = 0; j < data->height; j++)
		{
			printf("%f ", data->coordonates.destination_y[i][j]);
		}
		printf("\n");
	}
}

void print_x_coordinates(t_map *data)
{
	printf("X Coordinates:\n");
	for (int i = 0; i < data->width; i++)
	{
		for (int j = 0; j < data->height; j++)
		{
			printf("%f ", data->coordonates.destination_x[i][j]);
		}
		printf("\n");
	}
}