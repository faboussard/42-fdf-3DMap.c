#include "../includes/isometric_projection.h"
#include "libx.h"
#include "error_management.h"
#include <math.h>

double degree_to_radian()
{
	return (((20 * M_PI) / 120));
}

void calculate_destination_x(t_fdf *fdf, double radian, double resize)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->my_map.height)
	{
		j = 0;
		fdf->my_map.coordonates.destination_x[i] = malloc(sizeof(int) * fdf->my_map.width);
		if (fdf->my_map.coordonates.destination_x[i] == NULL)
			raise_error(FAILED_MALLOC, fdf);
		while (j < fdf->my_map.width)
		{
			fdf->my_map.coordonates.destination_x[i][j] = (float) (
					(fdf->my_map.coordonates.x[i][j] - ((fdf->my_map.coordonates.y[i][j]) * cos(radian))) * resize *
					-1);
			j++;
		}
		i++;
	}
}

void calculate_destination_y(t_fdf *fdf, double radian, double resize)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->my_map.height)
	{
		j = 0;
		fdf->my_map.coordonates.destination_y[i] = malloc(sizeof(int) * fdf->my_map.width);
		if (fdf->my_map.coordonates.destination_y[i] == NULL)
			raise_error(FAILED_MALLOC, fdf);
		while (j < fdf->my_map.width)
		{
			fdf->my_map.coordonates.destination_y[i][j] = (float) (
					(((fdf->my_map.coordonates.x[i][j] + fdf->my_map.coordonates.y[i][j]) * sin(radian) -
					  fdf->my_map.coordonates.z[i][j]) * resize));
			j++;
		}
		i++;
	}
}

double max_height(t_fdf *fdf)
{
	double delta;
	int i;
	int j;

	i = 0;
	delta = 0;
	while (i < fdf->my_map.width)
	{
		j = 0;
		while (j < fdf->my_map.height)
		{
			if (delta <= fdf->my_map.coordonates.y[i][j])
			{
				delta = fdf->my_map.coordonates.y[i][j];
			}
			j++;
		}
		i++;
	}
	return (delta);
}

void isometric_projection(t_fdf *fdf)
{
	int i;
	int j;
	double resize;
	double radian = degree_to_radian();

	max_height(fdf);
	double resize_x = 20;
	while ((resize_x * fdf->my_map.coordonates.x[0][0] >= WIDTH_DISPLAY)
	|| (resize_x * fdf->my_map.coordonates.x[i][j] >= WIDTH_DISPLAY))
		resize_x--;
	double resize_y = 20;
	while ((resize_y * fdf->my_map.coordonates.y[0][0]) >= HEIGHT_DISPLAY)
		resize_y--;
	//prendre le point le plus haut et le plus bas et dezoom si necessaire
	//implementer le zoom
	//regarder la correc
	resize = fmin(resize_x, resize_y);
	allocate_arrays(fdf, &fdf->my_map.coordonates.destination_x);
	allocate_arrays(fdf, &fdf->my_map.coordonates.destination_y);
	calculate_destination_x(fdf, radian, resize_x);
	calculate_destination_y(fdf, radian, resize_y);
}

