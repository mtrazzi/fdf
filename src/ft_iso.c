/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:24:34 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/20 18:39:48 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**ft_init_tab(int n, int p)
{
	t_point	**tab;
	int		i;

	i = 0;
	tab = (t_point **)malloc(sizeof(t_point *) * n);
	while (i < n)
	{
		tab[i] = (t_point *)malloc(sizeof(t_point) * p);
		i++;
	}
	return (tab);
}

void	ft_iso(t_env *e)
{
	int		x;
	int		y;
	t_pix	pix;

	x = 0;
	while (x < e->height)
	{
		y = 0;
		while (y < e->width)
		{
			if (e->tab[x][y] > 8)
				pix = ft_pixel_init(0, 0xff, 0, 0);
			else
				pix = ft_pixel_init(0, 0xff, 0xff, 0xff);
			(e->coord)[x][y] = ft_pt(y - x + e->height, ((x + y) - e->tab[x][y] / (e->height / 1000 + 1)), pix);
			y++;
		}
		x++;
	}
}
