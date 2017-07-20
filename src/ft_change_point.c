#include "fdf.h"

t_point	ft_pt(int x, int y, t_pix pix)
{
	t_point	t;

	t.x = x;
	t.y = y;
	t.pix = pix;
	return (t);
}
