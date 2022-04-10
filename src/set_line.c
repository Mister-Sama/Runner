/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** set_line - 2021
**
** *****************************************************************************
*/

#include "runner.h"

void                    std_set_line(t_bunny_pixelarray     *picture,
                                     t_bunny_position       *position,
                                     unsigned int           color)
{
  t_bunny_position      pos[1];
  float			i;
  float			j;

  i = 0;
  if ((DIFF(position[0].x, position[1].x)) > (DIFF(position[0].y, position[1].y)))
    j = 99.99 / (DIFF(position[0].x, position[1].x));
  else
    j = 99.99 / (DIFF(position[0].y, position[1].y));
  if ((DIFF(position[0].x, position[1].x)) == 0 && (DIFF(position[0].y, position[1].y)) == 0)
    i = 100;
  while (i < 100)
    {
      pos[0].x = position[0].x + std_get_value((i / 100), position[0].x,
                                               position[1].x);
      pos[0].y = position[0].y + std_get_value((i / 100), position[0].y,
                                               position[1].y);
      std_set_pixel(picture, pos[0], color);
      i = i + j;
    }
}

