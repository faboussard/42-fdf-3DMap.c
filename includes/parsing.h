#ifndef FDF_PARSING_H
#define FDF_PARSING_H

void init_coordonates(t_fdf *fdf);
void init_width(int fd, t_fdf *fdf);
void init_height(int fd, t_fdf *fdf);
void parse_map(int fd, t_fdf *fdf);

#endif //FDF_PARSING_H
