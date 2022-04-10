/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** draw_walls - 2021
**
** *****************************************************************************
*/

#include "runner.h"

static void		std_draw(t_parameter		*p,
				 t_raycast		*ray,
				 double			i)
{
  t_bunny_position pos[2];
  double perpualldist;

  if (ray->side == 0)
    perpualldist = (ray->map.x - p->start.x + (1-ray->step.x) / 2) / ray->dir.x;
  else
    perpualldist = (ray->map.y - p->start.y + (1-ray->step.y) / 2) / ray->dir.y;
  pos[0].x = p->px->clipable.buffer.width - i;
  pos[0].y = (p->px->clipable.buffer.height / 2) -
    (p->px->clipable.buffer.height * 0.25) / perpualldist;
  pos[1].x = p->px->clipable.buffer.width - i;
  pos[1].y = (p->px->clipable.buffer.height / 2) +
    (p->px->clipable.buffer.height * 0.25) / perpualldist;
  std_set_line(p->px, pos, (ray->side == 0) ? COLOR(255, 100, 100, 100) : COLOR(255, 200, 200, 200));
}

void			std_draw_walls(void		*data)
{
  double i;
  t_raycast ray;
  t_parameter		*p;

  i = 0;
  p = data;
  std_set_paysage(p->px, COLOR(255, 100, 100, 255), COLOR(255, 101, 67, 33));
  while (i != p->px->clipable.buffer.width)
    {
      std_start_raycast(p, &ray, i);
      std_send_ray(p, &ray);
      std_draw(p, &ray, i);
      i = i + 1;
    }
  bunny_blit(&p->win->buffer, &p->px->clipable, NULL);
  bunny_display(p->win);
}

