/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu005.cst.bunny.local>
**
** key_response - 2021
**
** *****************************************************************************
*/

#include			"runner.h"

static void			std_move(void		*data,
					 double		dir)
{
  t_parameter                   *p;
  t_bunny_accurate_position     nstart;
  
  p = data;
  nstart = p->start;
  nstart = std_walk_to(p->start, p->angle + dir, 0.2);
  if (p->map[(int) nstart.y * p->width + (int) nstart.x] == 0)
    {
      p->start = nstart;
      std_draw_walls(data);
    }
}

t_bunny_response		std_key_response(t_bunny_event_state        state,
						 t_bunny_keysym             sym,
						 void                       *data)
{
  if (state == GO_UP)
    return (GO_ON);
  if (sym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (sym == BKS_Z)
    std_move(data, 0);
  if (sym == BKS_S)
    std_move(data, M_PI);
  if (sym == BKS_Q)
    std_move(data, M_PI * 1.5);
  if (sym == BKS_D)
    std_move(data, M_PI * 0.5);
  return (GO_ON);
}

