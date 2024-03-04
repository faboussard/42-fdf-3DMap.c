/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:55:00 by faboussa          #+#    #+#             */
/*   Updated: 2024/03/02 15:32:39 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "draw.h"
#include "error_management.h"
#include "events.h"
#include "init.h"
#include "isometric_projection.h"
#include "mlx.h"
#include <X11/keysym.h>

void	destroy_and_recreate_img(t_fdf *fdf)
{
	ft_resize(fdf);
	mlx_destroy_image(fdf->my_libx.mlx, fdf->my_image.img);
	init_image(fdf);
	create_lines(fdf);
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == XK_Escape)
	{
		free_all(fdf);
		exit(EXIT_SUCCESS);
	}
	if (keycode == XK_space)
	{
		if (fdf->my_map.resize < 50)
		{
			reverse_resize(fdf);
			fdf->my_map.resize++;
			destroy_and_recreate_img(fdf);
		}
	}
	if (keycode == XK_Return)
	{
		if (fdf->my_map.resize > 1)
		{
			reverse_resize(fdf);
			fdf->my_map.resize--;
			destroy_and_recreate_img(fdf);
		}
	}
	return (0);
}

int	close_hook(t_fdf *fdf)
{
	free_all(fdf);
	exit(EXIT_SUCCESS);
}

void	ft_hook(t_fdf *fdf)
{
	mlx_hook(fdf->my_libx.win, ON_KEYDOWN, KEY_PRESS, key_hook, fdf);
}
