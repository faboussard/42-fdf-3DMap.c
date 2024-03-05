/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:55:00 by faboussa          #+#    #+#             */
/*   Updated: 2024/03/02 15:33:25 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "init.h"

void	create_lines(t_fdf *fdf);
void	my_pixel_put(t_fdf *fdf, int x, int y);
float	get_step(float *step, float *dx, float *dy);
void	draw_y(t_fdf *fdf, int i);
void	draw_x(t_fdf *fdf, int i);

#endif //DRAW_H
