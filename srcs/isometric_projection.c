/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:55:00 by faboussa          #+#    #+#             */
/*   Updated: 2024/03/02 15:32:39 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <math.h>
#include "isometric_projection.h"

void	calculate_destination_x(t_fdf *fdf, double radian)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->my_map.height)
	{
		j = 0;
		allocate_arrays(fdf, (int **)&fdf->my_map.coordonates.destination_x[i],
			fdf->my_map.width);
		while (j < fdf->my_map.width)
		{
			fdf->my_map.coordonates.destination_x[i][j]
				= (float)((fdf->my_map.coordonates.x[i][j]
						- ((fdf->my_map.coordonates.y[i][j]) * cos(radian)))
					*-1);
			while (fabsf(fdf->my_map.resize_factor_x
					* fdf->my_map.coordonates.destination_x[i][j])
				>= WIDTH_DISPLAY / 2)
				fdf->my_map.resize_factor_x--;
			j++;
		}
		i++;
	}
}

void	calculate_destination_y(t_fdf *fdf, double radian)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->my_map.height)
	{
		j = 0;
		allocate_arrays(fdf, (int **)&fdf->my_map.coordonates.destination_y[i],
			fdf->my_map.width);
		while (j < fdf->my_map.width)
		{
			fdf->my_map.coordonates.destination_y[i][j]
				= (float)((((fdf->my_map.coordonates.x[i][j]
								+ fdf->my_map.coordonates.y[i][j]) * sin(radian)
							- fdf->my_map.coordonates.z[i][j])));
			while (fabsf(fdf->my_map.resize_factor_y
					* fdf->my_map.coordonates.destination_y[i][j]) >=
					HEIGHT_DISPLAY / 3)
				fdf->my_map.resize_factor_y--;
			j++;
		}
		i++;
	}
}

void	isometric_projection(t_fdf *fdf)
{
	double	radian;

	radian = 20 * M_PI / 120;
	allocate_arrays(fdf, (int **)&fdf->my_map.coordonates.destination_x,
		fdf->my_map.height);
	allocate_arrays(fdf, (int **)&fdf->my_map.coordonates.destination_y,
		fdf->my_map.height);
	calculate_destination_x(fdf, radian);
	calculate_destination_y(fdf, radian);
	fdf->my_map.resize = (int)fmin(fdf->my_map.resize_factor_x,
			fdf->my_map.resize_factor_y);
	if (fdf->my_map.resize == 0)
		fdf->my_map.resize = 1;
	ft_resize(fdf);
}

void	ft_resize(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->my_map.height)
	{
		j = 0;
		while (j < fdf->my_map.width)
		{
			fdf->my_map.coordonates.destination_x[i][j] *= fdf->my_map.resize;
			fdf->my_map.coordonates.destination_y[i][j] *= fdf->my_map.resize;
			j++;
		}
		i++;
	}
}

void	reverse_resize(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->my_map.height)
	{
		j = 0;
		while (j < fdf->my_map.width)
		{
			fdf->my_map.coordonates.destination_x[i][j] /= fdf->my_map.resize;
			fdf->my_map.coordonates.destination_y[i][j] /= fdf->my_map.resize;
			j++;
		}
		i++;
	}
}
