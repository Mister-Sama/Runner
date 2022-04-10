/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** start_raycast - 2021
**
** *****************************************************************************
*/

#include "runner.h"

void       std_start_raycast(t_parameter		*p,
			     t_raycast			*ray,
			     double			i)
{
  t_bunny_accurate_position powdir;

  powdir.x = std_pow(ray->dir.x, 2);
  powdir.y = std_pow(ray->dir.y, 2);
  ray->ratio = (i - p->px->clipable.buffer.width / 2) / (p->px->clipable.buffer.width / 2);
  ray->dir.x = cos(p->angle) / 2 + cos(p->angle - M_PI / 2) * ray->ratio;
  ray->dir.y = sin(p->angle) / 2 + sin(p->angle - M_PI / 2) * ray->ratio;
  ray->map = std_position(p->start);
  ray->deltadist.x = std_sqrt(1 + powdir.y / powdir.x);
  ray->deltadist.y = std_sqrt(1 + powdir.x / powdir.y);
  std_set_step(p, ray);
}

