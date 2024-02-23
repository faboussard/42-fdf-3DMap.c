#include "../includes/init.h"

void init_map(t_map *data)
{
	data->height = 0;
	data->width = 0;
	data->coordonates.x = NULL;
	data->coordonates.y = NULL;
	data->coordonates.z = NULL;
	data->coordonates.destination_x = NULL;
	data->coordonates.destination_y = NULL;
}
