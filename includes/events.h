/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:55:00 by faboussa          #+#    #+#             */
/*   Updated: 2024/03/02 15:33:25 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "init.h"

enum	e_mask
{
	KEY_PRESS = 1L << 0,
};

enum	e_hooking_event
{
	ON_KEYDOWN = 2,
};

void	ft_hook(t_fdf *fdf);
int		close_hook(t_fdf *fdf);
int		key_hook(int keycode, t_fdf *fdf);
void	destroy_and_recreate_img(t_fdf *fdf);

#endif //EVENTS_H
