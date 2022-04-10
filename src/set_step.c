/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** set_step - 2021
**
** *****************************************************************************
*/

#include "runner.h"

void            std_set_step(t_parameter		*p,
			     t_raycast			*ray)
{
  if (ray->dir.x < 0)
    {
      ray->step.x = -1;
      ray->sidedist.x = (p->start.x-ray->map.x) * ray->deltadist.x;
    }
  else
    {
      ray->step.x = 1;
      ray->sidedist.x = (ray->map.x + 1 - p->start.x) * ray->deltadist.x;
    }
  if (ray->dir.y < 0)
    {
      ray->step.y = -1;
      ray->sidedist.y = (p->start.y-ray->map.y) * ray->deltadist.y;
    }
  else
    {
      ray->step.y = 1;
      ray->sidedist.y = (ray->map.y + 1 - p->start.y) * ray->deltadist.y;
    }
}

