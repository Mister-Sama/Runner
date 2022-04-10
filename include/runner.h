/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** runner - 2021
**
** *****************************************************************************
*/

#include		<lapin.h>
#include		<stdio.h>

#ifndef			__RUNNER_H__
#define			__RUNNER_H__
#define ABS(a)          ((a) < 0) ? (a) * -1 : (a)
#define DIFF(a, b)      ABS((a) - (b))

typedef struct			s_parameter
{
  t_bunny_window		*win;
  t_bunny_pixelarray		*px;
  t_bunny_accurate_position	start;
  double			angle;
  int				tile_size;
  int				width;
  int				height;
  int				*map;
}				t_parameter;

typedef struct			s_raycast
{
  float				ratio;
  t_bunny_accurate_position	dir;
  t_bunny_position		map;
  t_bunny_accurate_position	deltadist;
  t_bunny_position		step;
  t_bunny_accurate_position	sidedist;
  int				hit;
  int				side;
  double			perpualldist;
}				t_raycast;

t_bunny_position		std_position(t_bunny_accurate_position          pos);

void				std_set_paysage(t_bunny_pixelarray		*px,
						unsigned int			color1,
						unsigned int			color2);

void				std_set_line(t_bunny_pixelarray			*px,
					     t_bunny_position			*position,
					     unsigned int			color);

void				std_set_pixel(t_bunny_pixelarray		*px,
					      t_bunny_position			pos,
					      unsigned int			color);

double				std_get_value(double				ratio,
					      double				min,
					      double				max);

void				std_set_step(t_parameter			*p,
					     t_raycast				*ray);

void				std_start_raycast(t_parameter			*p,
						  t_raycast			*ray,
						  double			i);

void				std_send_ray(t_parameter			*p,
					     t_raycast				*ray);

t_bunny_response		std_key_response(t_bunny_event_state		state,
						 t_bunny_keysym			sym,
						 void				*data);

t_bunny_response		std_move_response(const t_bunny_position        *relative,
						  void                          *data);

void				std_draw_walls(void				*data);

t_bunny_accurate_position       std_walk_to(t_bunny_accurate_position		start,
                                            double				angle,
                                            double				len);

t_bunny_response		std_joy_connect_response(t_bunny_event_state	state,
							 int			joyid,
							 const t_bunny_joystick *joyinfo,
							 void			*data);

double				std_sqrt(double					nbr);

float				std_pow(float					a,
					int					b);


#endif

