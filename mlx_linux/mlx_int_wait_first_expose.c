/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_wait_first_expose.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:14:50 by faboussa          #+#    #+#             */
/*   Updated: 2024/02/18 20:14:50 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mlx_int_wait_first_expose.c for minilibx in 
** 
** Made by olivier crouzet
** Login   <ol@epita.fr>
** 
** Started on  Tue Oct 17 09:26:45 2000 olivier crouzet
** Last update Fri Feb 23 17:27:10 2001 Charlie Root
*/



#include	"mlx_int.h"



int	mlx_int_wait_first_expose(t_xvar *xvar,Window win)
{
  XEvent	ev;

  XWindowEvent(xvar->display,win,ExposureMask,&ev);
  XPutBackEvent(xvar->display,&ev);
}
