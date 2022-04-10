/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** position - 2021
**
** *****************************************************************************
*/

#include "runner.h"

t_bunny_position        std_position(t_bunny_accurate_position	pos)
{
  t_bunny_position	position;

  position.x = pos.x;
  position.y = pos.y;
  return (position);
}

