/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:55:00 by faboussa          #+#    #+#             */
/*   Updated: 2024/03/02 15:33:25 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# define WIDTH_DISPLAY 1920
# define HEIGHT_DISPLAY 1080

typedef struct s_libx
{
	void			*mlx;
	void			*win;
}					t_libx;

typedef struct s_image
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_image;

typedef struct s_coordonates
{
	int				**x;
	int				**y;
	int				**z;
	float			**destination_x;
	float			**destination_y;
}					t_coordonates;

typedef struct s_map
{
	int				height;
	int				width;
	int				resize_factor_x;
	int				resize_factor_y;
	int				resize;
	t_coordonates	coordonates;
}					t_map;

typedef struct s_fdf
{
	t_map			my_map;
	t_image			my_image;
	t_libx			my_libx;
	float			step_line;
	float			step_col;
	float			dx_line;
	float			dy_line;
	float			dx_col;
	float			dy_col;
}					t_fdf;

void				init_project(t_fdf *fdf);
void				init_window(t_fdf *fdf);
void				init_image(t_fdf *fdf);
void				allocate_arrays(t_fdf *fdf, int **coordonates, int size);

#endif //INIT_H
