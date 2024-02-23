#include "../includes/isometric_transform.h"
#include "libx.h"
#include "error_management.h"
#include <math.h>
#include "events.h"

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
//void draw_line(t_fdf *fdf, int x1, int y1, int x2, int y2)
//{
//	int	i;
//	int step;
//	int dx;
//	int dy;
//
//	dx = ft_abs(x2 - x1);
//	dy = ft_abs(y2 - y1);
//	if(dx >= dy)
//		step = dx;
//	else
//		step = dy;
//	i = 1;
//	while( i <= step)
//	{
//		my_mlx_pixel_put(fdf, x1 , y1, 0x00FF0000);
//		x1 = x1 + dx;
//		y1 = y1 + dy;
//		i++;
//	}
//}

//
//void create_lines(t_fdf *fdf)
//{
//	int i;
//	int j;
//
//	i = 0;
//	while (i < fdf->my_map.height)
//	{
//		j = 0;
//		while (j < fdf->my_map.width)
//		{
//			if (j + 1 < fdf->my_map.width)
//			{
//				draw_line(fdf, fdf->my_map.coordonates.destination_x[i][j], fdf->my_map.coordonates.destination_y[i][j],
//						  fdf->my_map.coordonates.destination_x[i][j + 1], fdf->my_map.coordonates.destination_y[i][j + 1]);
//			}
//			j++;
//		}
//		i++;
//	}
//	if (!mlx_put_image_to_window(fdf->my_libx.mlx, fdf->my_libx.win, fdf->my_image.img, 0, 0))
//		ft_error(NO_IMAGE, fdf);
//}


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
				my_mlx_pixel_put(fdf, fdf->my_map.coordonates.destination_x[i][j] , fdf->my_map.coordonates.destination_y[i][j], 0x00FF0000);
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
	int angle_radians;

	angle_radians = (int)(120 * M_PI / 180);
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
	create_lines(fdf);
//	print_x_coordinates_dest(data);
//	print_y_coordinates_dest(data);
}

