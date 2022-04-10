/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** set_paysage - 2021
**
** *****************************************************************************
*/

#include "runner.h"

void            std_set_paysage(t_bunny_pixelarray        *px,
                                unsigned int              color1,
                                unsigned int              color2)
{
  int           i;
  unsigned int  *adresse;

  i = 0;
  adresse = px->pixels;
  while (i != px->clipable.buffer.width * (px->clipable.buffer.height / 2))
    {
      adresse[i] = color1;
      i = i + 1;
    }
  while (i != px->clipable.buffer.width * px->clipable.buffer.height)
    {
      adresse[i] = color2;
      i = i + 1;
    }
}

