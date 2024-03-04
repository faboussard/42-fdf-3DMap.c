/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:55:00 by faboussa          #+#    #+#             */
/*   Updated: 2024/03/02 15:35:56 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "error_management.h"
#include "init.h"
#include "mlx.h"
#include <stddef.h>

void	init_project(t_fdf *fdf)
{
	fdf->my_map.resize_factor_x = 20;
	fdf->my_map.resize_factor_y = 20;
}

void	init_image(t_fdf *fdf)
{
	fdf->my_image.img = mlx_new_image(fdf->my_libx.mlx, 1920, 1080);
	if (fdf->my_image.img == NULL)
	{
		free_all(fdf);
		exit(EXIT_FAILURE);
	}
	fdf->my_image.addr = mlx_get_data_addr(fdf->my_image.img,
			&fdf->my_image.bits_per_pixel, &fdf->my_image.line_length,
			&fdf->my_image.endian);
}

void	init_window(t_fdf *fdf)
{
	fdf->my_libx.mlx = mlx_init();
	if (fdf->my_libx.mlx == NULL)
		exit(EXIT_FAILURE);
	fdf->my_libx.win = mlx_new_window(fdf->my_libx.mlx, WIDTH_DISPLAY,
			HEIGHT_DISPLAY, "Fafa Fdf");
	if (fdf->my_libx.win == NULL)
	{
		free_all(fdf);
		exit(EXIT_FAILURE);
	}
	init_image(fdf);
}

void	init_coordonates(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	allocate_arrays(fdf, (int **)&fdf->my_map.coordonates.x,
		fdf->my_map.height);
	allocate_arrays(fdf, (int **)&fdf->my_map.coordonates.y,
		fdf->my_map.height);
	while (i < fdf->my_map.height)
	{
		j = 0;
		fdf->my_map.coordonates.x[i] = malloc(sizeof(int) * fdf->my_map.width);
		fdf->my_map.coordonates.y[i] = malloc(sizeof(int) * fdf->my_map.width);
		if (fdf->my_map.coordonates.x[i] == NULL
			|| fdf->my_map.coordonates.y[i] == NULL)
			raise_error(FAILED_MALLOC, fdf, 0);
		while (j < fdf->my_map.width)
		{
			fdf->my_map.coordonates.y[i][j] = j;
			fdf->my_map.coordonates.x[i][j] = i;
			j++;
		}
		i++;
	}
}

void	allocate_arrays(t_fdf *fdf, int **coordonates, int size)
{
	if (coordonates)
	{
		*coordonates = malloc(size * sizeof(int *));
		if (*coordonates == NULL)
			raise_error(FAILED_MALLOC, fdf, 0);
		ft_bzero(*coordonates, sizeof(coordonates));
	}
}
