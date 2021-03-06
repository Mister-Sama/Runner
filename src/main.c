/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** main - 2021
**
** *****************************************************************************
*/

#include "runner.h"

int main(void)
{
  t_parameter p;
  int mx[6 * 6] = {
    1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 1, 1,
    1, 1, 1, 0, 0, 1,
    1, 1, 1, 0, 1, 1,
    1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1,
  };
  p.width = 6;
  p.height = 6;
  p.tile_size = 100;
  p.map = &mx[0];
  p.start.x = 1.5;
  p.start.y = 1.5;
  p.angle = 0;
  p.win = bunny_start(1080, 1080, false, "Runner");
  p.px = bunny_new_pixelarray(p.win->buffer.width, p.win->buffer.height);
  std_draw_walls(&p);
  bunny_set_mouse_visibility(p.win, false);
  bunny_set_key_response(std_key_response);
  bunny_set_move_response(std_move_response);
  bunny_loop(p.win, 60, &p);
  bunny_stop(p.win);
  return (0);
}

