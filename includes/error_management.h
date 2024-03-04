/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa  <faboussa@student.42lyon.f>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:55:00 by faboussa          #+#    #+#             */
/*   Updated: 2024/03/02 15:33:25 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H

# include "init.h"
# include <stddef.h>

enum	e_error
{
	FAILED_MALLOC,
	FAILED_OPENING,
	NO_IMAGE,
};

void	raise_error(enum e_error error_code, t_fdf *fdf, int *fd);
void	ft_free_split(char **tab);
void	ft_free_tab(void **tab, int j);
void	free_all(t_fdf *fdf);

#endif //ERROR_MANAGEMENT_H
