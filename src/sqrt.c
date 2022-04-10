#include	"runner.h"

double		std_sqrt(double		nbr)
{
  double	sqrt;

  sqrt = nbr;
  while (sqrt - nbr / sqrt > 0.01)
    sqrt = (sqrt + nbr / sqrt) / 2;
  return (sqrt);
}
