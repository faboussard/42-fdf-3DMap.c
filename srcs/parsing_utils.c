/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
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

void	init_height(int fd, t_fdf *fdf)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	i = 1;
	while (line != NULL && line[0] != '\n')
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (line)
		free(line);
	fdf->my_map.height = i;
}

void	init_width(int fd, t_fdf *fdf)
{
	int		i;
	char	*line;
	char	**split_lines;

	line = get_next_line(fd);
	if (line == NULL)
		raise_error(FAILED_MALLOC, fdf, &fd);
	i = 0;
	split_lines = ft_split(line, ' ');
	free(line);
	if (split_lines == NULL)
		raise_error(FAILED_MALLOC, fdf, &fd);
	while (split_lines[i] != NULL)
		i++;
	ft_free_tab((void **) split_lines, i);
	fdf->my_map.width = i;
}
