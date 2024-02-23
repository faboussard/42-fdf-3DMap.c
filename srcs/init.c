#include "../includes/init.h"

void init(t_fdf *fdf)
{
	ft_bzero(fdf, sizeof(*fdf));
	fdf->my_libx.mlx = mlx_init();
	fdf->my_libx.win = mlx_new_window(fdf->my_libx.mlx, SIZE_X, SIZE_Y, "Fafa Fdf");
	fdf->my_image.img = mlx_new_image(fdf->my_libx.mlx, 1920, 1080);
	fdf->my_image.addr = mlx_get_data_addr(fdf->my_image.img, &fdf->my_image.bits_per_pixel, &fdf->my_image.line_length,
								 &fdf->my_image.endian);
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->my_image.addr + (y * fdf->my_image.line_length + x * (fdf->my_image.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
