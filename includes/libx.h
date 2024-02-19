
#ifndef FDF_LIBX_H
#define FDF_LIBX_H

#include "../mlx_linux/mlx.h"

typedef struct t_fdf
{
	void	*mlx;
	void	*win;
}	t_fdf;

enum key{
	LEFT_KEY = 65361,
	ESC = 65307,
} e_key ;

enum mask{
	KEY_PRESS = 1L<<0,
	KEY_RELEASE = 1L<<1,
	BUTTON_PRESS = 1L<<2,
	BUTTON_RELEASE = 1L<<3,
		} e_mask;

enum hooking_event{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
};

#endif //FDF_LIBX_H
