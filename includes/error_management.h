
#ifndef FDF_ERROR_MANAGEMENT_H
#define FDF_ERROR_MANAGEMENT_H

enum e_error{
	FAILED_MALLOC,
	FAILED_OPENING,
	WRONG_MAP,


};

void ft_error(enum e_error error_code);

#endif //FDF_ERROR_MANAGEMENT_H
