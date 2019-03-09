

#ifndef UTILS_H
# define UTILS_H

typedef struct  xy
{
    float x;
    float y;
}               xy;

typedef struct  xyz
{
    float x;
    float y;
    float z;
}               xyz;

xy new_xy(float x, float y);

xyz new_xyz(float x, float y, float z);

xy intersect(xy xy1, xy xy2, xy xy3, xy xy4);

int intersect_box(xy xy0, xy xy1, xy xy2, xy xy3);

int intersect_box_handle(xy p, xy d, xy* vert, int s);

float point_side(xy p, xy xy0, xy xy1);

float point_side_handle(xy p, xy d, xy* vert, int s);

#endif