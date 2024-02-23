#include "../libft/inc/libft.h"
#include "../includes/error_management.h"
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
}

void ft_error(enum e_error error_code, t_fdf *fdf)
{
	if (error_code == FAILED_MALLOC)
		perror("malloc failed");
	if (error_code == FAILED_OPENING)
		ft_putstr_fd("file did not open properly\n", STDERR_FILENO);
	if (error_code == WRONG_MAP)
		ft_putstr_fd("data to parse does not form a square\n", STDERR_FILENO);
	free_all(fdf);
	exit(EXIT_FAILURE);
}