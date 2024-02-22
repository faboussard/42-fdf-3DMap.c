
#ifndef FDF_ERROR_MANAGEMENT_H
#define FDF_ERROR_MANAGEMENT_H

#include "../includes/init.h"

enum e_error{
	FAILED_MALLOC,
	FAILED_OPENING,
	WRONG_MAP,
};

void ft_error(enum e_error error_code, t_map *data);
void free_split(char **split);

#endif //FDF_ERROR_MANAGEMENT_H
