/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:55:00 by faboussa          #+#    #+#             */
/*   Updated: 2024/03/02 15:32:39 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "error_management.h"
#include "init.h"
#include "mlx.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_free_strs_array(char **strs_array, size_t start)
{
	size_t	i;

	i = 0;
	while (i < start)
	{
		free(strs_array[i]);
		i++;
	}
	free(strs_array);
	return (NULL);
}

void	ft_free_tab(int **tab, int j)
{
	int	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_all(t_fdf *fdf)
{
	if (fdf->my_map.coordonates.x)
		ft_free_tab(fdf->my_map.coordonates.x, fdf->my_map.height);
	if (fdf->my_map.coordonates.y)
		ft_free_tab(fdf->my_map.coordonates.y, fdf->my_map.height);
	if (fdf->my_map.coordonates.z)
		ft_free_tab(fdf->my_map.coordonates.z, fdf->my_map.height);
	if (fdf->my_map.coordonates.destination_x)
		ft_free_tab((int **)fdf->my_map.coordonates.destination_x,
			fdf->my_map.height);
	if (fdf->my_map.coordonates.destination_y)
		ft_free_tab((int **)fdf->my_map.coordonates.destination_y,
			fdf->my_map.height);
	if (fdf->my_image.img)
		mlx_destroy_image(fdf->my_libx.mlx, fdf->my_image.img);
	if (fdf->my_libx.win)
		mlx_destroy_window(fdf->my_libx.mlx, fdf->my_libx.win);
	if (fdf->my_libx.mlx)
		mlx_destroy_display(fdf->my_libx.mlx);
	free(fdf->my_libx.mlx);
}

void	raise_error(enum e_error error_code, t_fdf *fdf, int *fd)
{
	if (fd)
		close(*fd);
	if (error_code == EMPTY_MAP)
		ft_putstr_fd("data to parse is not a number. Exit.\n", STDERR_FILENO);
	if (error_code == WRONG_DATA_IN_MAP)
		ft_putstr_fd("data to parse is not a number. Exit.\n", STDERR_FILENO);
	if (error_code == WRONG_ARGS)
		ft_putstr_fd("Wrong arguments entered. Exit\n", STDERR_FILENO);
	if (error_code == FAILED_MALLOC)
		ft_putstr_fd("malloc failed. empty data. Exit\n", STDERR_FILENO);
	if (error_code == FAILED_OPENING)
		ft_putstr_fd("file could not open. Check name and properties. Exit\n",
			STDERR_FILENO);
	if (error_code == WRONG_MAP)
		ft_putstr_fd("data to parse does not form a square. Exit\n",
			STDERR_FILENO);
	if (error_code == NO_IMAGE)
		ft_putstr_fd("image could not be rendered. Exit.\n", STDERR_FILENO);
	free_all(fdf);
	exit(EXIT_FAILURE);
}
