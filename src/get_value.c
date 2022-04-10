/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** get_value - 2021
**
** *****************************************************************************
*/

#include "runner.h"

double           std_get_value(double             ratio,
                              double             min,
                              double             max)
{
  return (ratio * (max - min));
}

