/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:55:00 by faboussa          #+#    #+#             */
/*   Updated: 2024/03/02 15:32:39 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "draw.h"
#include "events.h"
#include "init.h"
#include "isometric_projection.h"
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_fdf		fdf;
	int			fd;
	const char	*file_name;

	file_name = argv[1];
	fd = open(file_name, O_RDONLY);
	if (argc != 2 || fd < 0)
	{
		ft_putstr_fd("Map doest not exist. Exit.\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_bzero(&fdf, sizeof(fdf));
	init_project(&fdf);
	init_window(&fdf);
	ft_hook(&fdf);
	mlx_hook(fdf.my_libx.win, 17, 0, close_hook, &fdf);
	init_data(&fdf, file_name);
	isometric_projection(&fdf);
	create_lines(&fdf);
	mlx_loop(fdf.my_libx.mlx);
	exit(EXIT_SUCCESS);
}
