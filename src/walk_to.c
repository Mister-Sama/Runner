/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu012.cst.bunny.local>
**
** walk_to - 2021
**
** *****************************************************************************
*/

#include "runner.h"

t_bunny_accurate_position       std_walk_to(t_bunny_accurate_position   start,
                                            double                      angle,
                                            double                      len)
{
  t_bunny_accurate_position     pos;

  pos.x = start.x + cos(angle) * len;
  pos.y = start.y + sin(angle) * len;
  return (pos);
}

