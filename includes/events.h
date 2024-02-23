
#ifndef FDF_EVENTS_H
#define FDF_EVENTS_H

#include "init.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

enum e_key{
	LEFT_KEY = 65361,
	ESC = 65307,
};

enum e_mask{
	KEY_PRESS = 1L<<0,
	KEY_RELEASE = 1L<<1,
	BUTTON_PRESS = 1L<<2,
	BUTTON_RELEASE = 1L<<3,
} ;

enum e_hooking_event{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
};

void ft_hook(t_fdf *fdf);
int	close_hook(t_fdf *fdf);
int quit(t_fdf *fdf);

#endif //FDF_EVENTS_H
