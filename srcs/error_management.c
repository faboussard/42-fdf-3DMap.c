#include "../libft/inc/libft.h"
#include "../includes/error_management.h"
#include <stdio.h>

void free_all(t_map *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->coordonates.x[i]);
		i++;
	}
	free(data->coordonates.x);
	i = 0;
	while (i < data->width)
	{
		free(data->coordonates.y[i]);
		free(data->coordonates.z[i]);
		i++;
	}
	free(data->coordonates.y);
//	free(data);
}

void ft_error(enum e_error error_code, t_map *data)
{
	if (error_code == FAILED_MALLOC)
		perror("malloc failed");
	if (error_code == FAILED_OPENING)
		ft_putstr_fd("file did not open properly\n", STDERR_FILENO);
	if (error_code == WRONG_MAP)
		ft_putstr_fd("data to parse does not form a square\n", STDERR_FILENO);
	free_all(data);
	exit(EXIT_FAILURE);
}