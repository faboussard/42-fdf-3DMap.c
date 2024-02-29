
#ifndef FDF_EVENTS_H
#define FDF_EVENTS_H

#include "init.h"

enum e_mask{
	KEY_PRESS = 1L<<0,
} ;

enum e_hooking_event{
	ON_KEYDOWN = 2,
};

void ft_hook(t_fdf *fdf);
int	close_hook(t_fdf *fdf);

#endif //FDF_EVENTS_H
