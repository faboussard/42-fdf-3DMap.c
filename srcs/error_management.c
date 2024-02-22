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

void free_all(t_map *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		if (data->coordonates.x[i])
			free(data->coordonates.x[i]);
		i++;
	}
	free(data->coordonates.x);
	i = 0;
	while (i < data->width)
	{
		if (data->coordonates.y[i])
			free(data->coordonates.y[i]);
		if (data->coordonates.z[i])
			free(data->coordonates.z[i]);
		i++;
	}
	free(data->coordonates.y);
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