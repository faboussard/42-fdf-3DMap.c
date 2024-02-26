#include "../libft/inc/libft.h"
#include "../includes/error_management.h"
#include "events.h"
#include <stdio.h>

void free_split(char **split)
{
	int	i;

	i = 0;
	if (split != NULL && *split != NULL)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

void	ft_free(int **tab, int j)
{
	if (tab == NULL)
		return;
	int	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void free_all(t_fdf *fdf)
{
	ft_free(fdf->my_map.coordonates.x, fdf->my_map.height);
	ft_free(fdf->my_map.coordonates.y, fdf->my_map.height);
	ft_free(fdf->my_map.coordonates.z, fdf->my_map.height);
	ft_free(fdf->my_map.coordonates.destination_x, fdf->my_map.height);
	ft_free(fdf->my_map.coordonates.destination_y, fdf->my_map.height);
//	free(fdf->my_image.img);
//	free(fdf->my_libx.win);
//	free(fdf->my_libx.mlx);
}

void raise_error(enum e_error error_code, t_fdf *data)
{
	if (error_code == FAILED_MALLOC)
		ft_putstr_fd("malloc failed. Exit\n", STDERR_FILENO);
	if (error_code == FAILED_OPENING)
		ft_putstr_fd("file did not open properly. Exit\n", STDERR_FILENO);
	if (error_code == WRONG_MAP)
		ft_putstr_fd("data to parse does not form a square. Exit\n", STDERR_FILENO);
	if (error_code == NO_IMAGE)
		ft_putstr_fd("image cannot be rendered. Exit.\n", STDERR_FILENO);
	mlx_destroy_window(data->my_libx.mlx, data->my_libx.win);
	mlx_destroy_display(data->my_libx.mlx);
	free_all(data);
	exit(EXIT_FAILURE);
}