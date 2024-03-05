/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:55:00 by faboussa          #+#    #+#             */
/*   Updated: 2024/03/02 15:33:25 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "init.h"

void	init_data(t_fdf *fdf, const char *filename);
void	init_height(int fd, t_fdf *fdf);
void	init_width(int fd, t_fdf *fdf);
void	init_coordonates(t_fdf *fdf);
void	allocate_arrays(t_fdf *fdf, int **coordonates, int size);
char	**parse_line(int fd, t_fdf *fdf);
void	parse_map(int fd, t_fdf *fdf);
void	check_map(int fd, t_fdf *fdf);

#endif //PARSING_H
