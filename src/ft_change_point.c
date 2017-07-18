#include "fdf.h"

t_point	ft_point_init(void *mlx, void *win, int x, int y)
{
	t_point	t;

	t.x = x;
	t.y = y;
	t.mlx = mlx;
	t.win = win;
	return (t);
}

t_point	*ft_change_point(t_point *s, int x, int y)
{
	s->x = x;
	s->y = y;
	return (s);
}
