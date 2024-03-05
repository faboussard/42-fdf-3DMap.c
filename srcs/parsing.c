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
#include "parsing.h"

void	init_data(t_fdf *fdf, const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		raise_error(FAILED_OPENING, fdf, 0);
	init_width(fd, fdf);
	init_height(fd, fdf);
	init_coordonates(fdf);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		raise_error(FAILED_OPENING, fdf, 0);
	check_map(fd, fdf);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		raise_error(FAILED_OPENING, fdf, 0);
	parse_map(fd, fdf);
	close(fd);
}

char	**parse_line(int fd, t_fdf *fdf)
{
	char	**split_lines;
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		raise_error(FAILED_MALLOC, fdf, &fd);
	split_lines = ft_split(line, ' ');
	free(line);
	if (split_lines == NULL)
		raise_error(FAILED_MALLOC, fdf, &fd);
	return (split_lines);
}

void	parse_map(int fd, t_fdf *fdf)
{
	int		i;
	int		j;
	char	**split_lines;

	i = 0;
	allocate_arrays(fdf, (int **)&fdf->my_map.coordonates.z,
		fdf->my_map.height);
	while (i < fdf->my_map.height)
	{
		allocate_arrays(fdf, &fdf->my_map.coordonates.z[i], fdf->my_map.width);
		split_lines = parse_line(fd, fdf);
		if (split_lines == NULL)
			raise_error(FAILED_MALLOC, fdf, &fd);
		j = 0;
		while (j < fdf->my_map.width)
		{
			fdf->my_map.coordonates.z[i][j] = ft_atoi(split_lines[j]);
			j++;
		}
		ft_free_split(split_lines);
		i++;
	}
}

void	check_map(int fd, t_fdf *fdf)
{
	int		i;
	int		j;
	char	**split_lines;

	i = 0;
	while (i < fdf->my_map.height)
	{
		split_lines = parse_line(fd, fdf);
		j = 0;
		while (j < fdf->my_map.width)
		{
			if (split_lines[j] == NULL)
			{
				ft_free_split(split_lines);
				raise_error(FAILED_MALLOC, fdf, &fd);
			}
			j++;
		}
		ft_free_split(split_lines);
		i++;
	}
}
