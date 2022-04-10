/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** send_ray - 2021
**
** *****************************************************************************
*/

#include "runner.h"

void    std_send_ray(t_parameter	*p,
                     t_raycast          *ray)
{
  ray->hit = 0;
  while (ray->hit == 0)
    {
      if (ray->sidedist.y <= 0 || (ray->sidedist.x >= 0 && ray->sidedist.x < ray->sidedist.y))
        {
          ray->sidedist.x = ray->sidedist.x + ray->deltadist.x;
          ray->map.x = ray->map.x + ray->step.x;
          ray->side = 0;
        }
      else
        {
          ray->sidedist.y = ray->sidedist.y + ray->deltadist.y;
          ray->map.y = ray->map.y + ray->step.y;
          ray->side = 1;
        }
      if (ray->map.x >= p->width || ray->map.x < 0 || ray->map.y >= p->height || ray->map.y < 0)
        ray->hit = 1;
      if (p->map[ray->map.y * p->width + ray->map.x] != 0)
        ray->hit = 1;
    }
}

