#include "../libft/inc/libft.h"
#include "../includes/error_management.h"
#include <stdio.h>

void ft_error(enum e_error error_code)
{
	if (error_code == FAILED_MALLOC)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	if (error_code == FAILED_OPENING)
	{
		ft_putstr_fd("file did not open properly\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (error_code == WRONG_MAP)
	{
		ft_putstr_fd("data to parse does not form a square\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}