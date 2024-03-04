/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:58:19 by faboussa          #+#    #+#             */
/*   Updated: 2024/03/04 18:58:19 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "init.h"
#include "mlx.h"
#include <math.h>

void	my_pixel_put(t_fdf *fdf, int x, int y)
{
	char	*dst;
	int		offset_x;
	int		offset_y;

	offset_x = x * (fdf->my_image.bits_per_pixel / 8);
	offset_y = y * fdf->my_image.line_length;
	if (x >= 0 && x < WIDTH_DISPLAY && y >= 0 && y < HEIGHT_DISPLAY)
	{
		dst = fdf->my_image.addr + ft_abs(offset_x + offset_y);
		*(unsigned int *)dst = 0x00FF0000;
	}
}

float	get_step(float *step, float *dx, float *dy)
{
	if (fabsf(*dx) >= fabsf(*dy))
		*step = fabsf(*dx);
	else
		*step = fabsf(*dy);
	*dx /= *step;
	*dy /= *step;
	return (*step);
}

void	draw_y(t_fdf *fdf, int i)
{
	int		j;
	float	x;
	float	y;
	float	step;

	j = 0;
	while (j < fdf->my_map.height - 1)
	{
		x = fdf->my_map.coordonates.destination_x[j][i];
		y = fdf->my_map.coordonates.destination_y[j][i];
		fdf->dx_col = fdf->my_map.coordonates.destination_x[j + 1][i]
			- fdf->my_map.coordonates.destination_x[j][i];
		fdf->dy_col = fdf->my_map.coordonates.destination_y[j + 1][i]
			- fdf->my_map.coordonates.destination_y[j][i];
		step = get_step(&fdf->step_col, &fdf->dx_col, &fdf->dy_col);
		while (step-- > 0)
		{
			x += fdf->dx_col;
			y += fdf->dy_col;
			my_pixel_put(fdf, (int)(x + WIDTH_DISPLAY / 2.5),
				(int)(y + HEIGHT_DISPLAY / 3.0));
		}
		j++;
	}
}

void	draw_x(t_fdf *fdf, int i)
{
	int		j;
	float	x;
	float	y;
	float	step;

	j = 0;
	while (j < fdf->my_map.width - 1)
	{
		x = fdf->my_map.coordonates.destination_x[i][j];
		y = fdf->my_map.coordonates.destination_y[i][j];
		fdf->dx_line = fdf->my_map.coordonates.destination_x[i][j + 1]
			- fdf->my_map.coordonates.destination_x[i][j];
		fdf->dy_line = fdf->my_map.coordonates.destination_y[i][j + 1]
			- fdf->my_map.coordonates.destination_y[i][j];
		step = get_step(&fdf->step_line, &fdf->dx_line, &fdf->dy_line);
		while (step-- > 0)
		{
			x += fdf->dx_line;
			y += fdf->dy_line;
			my_pixel_put(fdf, (int)(x + WIDTH_DISPLAY / 2.5),
				(int)(y + HEIGHT_DISPLAY / 3.0));
		}
		j++;
	}
}

void	create_lines(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->my_map.height)
	{
		draw_x(fdf, i);
		i++;
	}
	i = 0;
	while (i < fdf->my_map.width)
	{
		draw_y(fdf, i);
		i++;
	}
	mlx_put_image_to_window(fdf->my_libx.mlx, fdf->my_libx.win,
		fdf->my_image.img, 0, 0);
}
