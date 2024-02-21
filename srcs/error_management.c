#include "../libft/inc/libft.h"
#include "../includes/error_management.h"
#include <stdio.h>

void error(enum e_error error_code)
{
	if (error_code == FAILED_MALLOC)
	{
		perror("malloc_failed");
		exit(EXIT_FAILURE);
	}
	if (error_code == FAILED_OPENING)
	{
		perror("error openneing file");
		exit(EXIT_FAILURE);
	}
}