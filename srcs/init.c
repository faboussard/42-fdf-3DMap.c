#include "../includes/init.h"

void init(t_fdf *fdf)
{
	ft_bzero(fdf, sizeof(*fdf));
	fdf->my_libx.mlx = mlx_init();
	if (fdf->my_libx.mlx == NULL)
		exit(EXIT_FAILURE);
	fdf->my_libx.win = mlx_new_window(fdf->my_libx.mlx, SIZE_X, SIZE_Y, "Fafa Fdf");
	if (fdf->my_libx.win == NULL)
		exit(EXIT_FAILURE);
	fdf->my_image.img = mlx_new_image(fdf->my_libx.mlx, 1920, 1080);
	if (fdf->my_image.img == NULL)
		exit(EXIT_FAILURE);
	fdf->my_image.addr = mlx_get_data_addr(fdf->my_image.img, &fdf->my_image.bits_per_pixel, &fdf->my_image.line_length,
								 &fdf->my_image.endian);
}
