
#ifndef FDF_ERROR_MANAGEMENT_H
#define FDF_ERROR_MANAGEMENT_H

#include "../includes/init.h"

enum e_error{
	MLX_ERROR,
	FAILED_MALLOC,
	FAILED_OPENING,
	WRONG_MAP,
	NO_IMAGE,
};

void ft_error(enum e_error error_code, t_fdf *data);
void free_split(char **split);
void free_all(t_fdf *fdf);

#endif //FDF_ERROR_MANAGEMENT_H
