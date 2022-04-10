#include	"runner.h"

float             std_pow(float   a,
			int     b)
{
  int           p;
  float         u;

  p = 1;
  u = a;
  if (b == 0)
    return (a);
  if (b < 0)
      return (-1);
  while (p != b)
    {
      u = u * a;
      p = p + 1;
    }
  return (u);
}
