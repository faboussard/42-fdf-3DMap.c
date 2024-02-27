#include "../includes/isometric_transform.h"
#include "libx.h"
#include "error_management.h"
#include <math.h>

double degree_to_radian()
{
	return (((20 * M_PI) / 120));
}

void calculate_destination_x(t_fdf *fdf, double radian, double resize)
{
	int	i;
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
			fdf->my_map.coordonates.destination_x[i][j] = (float)(
					(fdf->my_map.coordonates.x[i][j] - ((fdf->my_map.coordonates.y[i][j]) * cos(radian))) * resize * -1);
			j++;
		}
		i++;
	}
}

void calculate_destination_y(t_fdf *fdf, double radian, double resize)
{
	int	i;
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
			fdf->my_map.coordonates.destination_y[i][j] = (float)(
					(((fdf->my_map.coordonates.x[i][j] + fdf->my_map.coordonates.y[i][j]) * sin(radian) -
					  fdf->my_map.coordonates.z[i][j]) * resize));
			j++;
		}
		i++;
	}
}

void isometric_projection(t_fdf *fdf)
{
	double	radian;
	double	resize;

	double maxSize = 10;
	radian = degree_to_radian();
//	resize = fabsf((float)((fdf->my_map.height + fdf->my_map.height - fdf->my_map.width) * sqrt(fdf->my_map.width * 5)));
//
//	// Vérifier si le resize dépasse la taille maximale
//	if (resize > SIZE_Y) {
//		resize = maxSize; // Réduire le resize à la taille maximale
//	}
resize = 0.2;
	allocate_arrays(fdf, &fdf->my_map.coordonates.destination_x);
	allocate_arrays(fdf, &fdf->my_map.coordonates.destination_y);
	calculate_destination_x(fdf, radian, resize);
	calculate_destination_y(fdf, radian, resize);
}
