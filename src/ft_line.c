/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:57:38 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/20 19:58:08 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	ft_line_init(int dx, int dy, int err)
{
	t_line	t;

	t.dx = dx;
	t.dy = dy;
	t.err = err;
	return (t);
}

void	ft_put_line(t_point p1, t_point p2, t_env *e)
{
	int		e2;
	t_line	t;
	int		x;
	int		y;
	int sum = 0;
	int scale;

	p1.x *= e->scale;
	p1.y *= e->scale;
	p2.x *= e->scale;
	p2.y *= e->scale;
	scale = e->scale;
	e->scale = 1;
	t = ft_line_init(abs(p1.x - p2.x), abs(p1.y - p2.y), \
abs(p1.x - p2.x) > abs(p1.y - p2.y) ? abs(p1.x - p2.x) : -abs(p1.y - p2.y));
	while (!(p1.x == p2.x && p1.y == p2.y))
	{
		e->d = ft_change_pix(*e, ft_mix(p1.pix, p2.pix), p1.x, p1.y);
		e2 = t.err;
		if (e2 > -t.dx)
		{
			t.err -= t.dy;
			p1.x += (p1.x < p2.x ? 1 : -1);
		}
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		if (e2 < t.dy)
		{
			t.err += t.dx;
			p1.y += (p1.y < p2.y ? 1 : -1);
		}
		sum++;
	}
	e->scale = scale;
}

void	ft_process_pt(int x, int y, t_env *e)
{
	t_point	**coord;

	coord = e->coord;
	if (x < e->height - 1)
		ft_put_line(coord[x][y], coord[x + 1][y], e);
	if (y < e->width - 1)
		ft_put_line(coord[x][y], coord[x][y + 1], e);
}
