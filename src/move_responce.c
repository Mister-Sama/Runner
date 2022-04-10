/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu005.cst.bunny.local>
**
** move_response - 2021
**
** *****************************************************************************
*/

#include	"runner.h"

t_bunny_response	std_move_response(const t_bunny_position	*relative,
					  void				*data)
{
  const t_bunny_position	*pos;
  t_parameter			*p;
  (void) relative;

  p = data;
  pos = bunny_get_mouse_position();
  if (pos->x > p->win->buffer.width * 0.70)
    {
      p->angle = p->angle + 0.1;
      bunny_set_mouse_position_window(p->win, p->win->buffer.width / 2, p->win->buffer.height / 2);
      std_draw_walls(data);
    }
  if (pos->x < p->win->buffer.width * 0.30)
    {
      p->angle = p->angle - 0.1;
      bunny_set_mouse_position_window(p->win, p->win->buffer.width / 2, p->win->buffer.height / 2);
      std_draw_walls(data);
    }
  if (p->angle == M_PI || p->angle == -M_PI)
    p->angle = 0;
  return (GO_ON);
}
