#include "../libft/inc/libft.h"
#include "../includes/error_management.h"
#include "mlx.h"

void ft_free(int **tab, int j)
{
	if (tab == NULL)
		return;
	int i;

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
	if (fdf->my_map.coordonates.x)
	{
		ft_free(fdf->my_map.coordonates.x, fdf->my_map.height);
		ft_free(fdf->my_map.coordonates.y, fdf->my_map.height);
		ft_free(fdf->my_map.coordonates.z, fdf->my_map.height);
		ft_free((int **) fdf->my_map.coordonates.destination_x, fdf->my_map.height);
		ft_free((int **) fdf->my_map.coordonates.destination_y, fdf->my_map.height);
	}
	if (fdf->my_image.img)
		mlx_destroy_image(fdf->my_libx.mlx, fdf->my_image.img);
	if (fdf->my_libx.win)
		mlx_destroy_window(fdf->my_libx.mlx, fdf->my_libx.win);
	if (fdf->my_libx.mlx)
		mlx_destroy_display(fdf->my_libx.mlx);
	free(fdf->my_libx.mlx);
}

void raise_error(enum e_error error_code, t_fdf *fdf)
{
	if (error_code == WRONG_ARGS)
		ft_putstr_fd("Wrong arguments entered. Exit\n", STDERR_FILENO);
	if (error_code == FAILED_MALLOC)
		ft_putstr_fd("malloc failed. Exit\n", STDERR_FILENO);
	if (error_code == FAILED_OPENING)
		ft_putstr_fd("file could not open. Check name and properties. Exit\n", STDERR_FILENO);
	if (error_code == WRONG_MAP)
		ft_putstr_fd("data to parse does not form a square. Exit\n", STDERR_FILENO);
	if (error_code == NO_IMAGE)
		ft_putstr_fd("image could not be rendered. Exit.\n", STDERR_FILENO);
	free_all(fdf);
	exit(EXIT_FAILURE);
}