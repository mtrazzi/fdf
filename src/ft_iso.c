/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:24:34 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/20 15:23:03 by mtrazzi          ###   ########.fr       */
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

	x = 0;
	while (x < e->width)
	{
		y = 0;
		while (y < e->height)
		{
			(e->coord)[x][y] = ft_pt(x - y + e->height, ((x + y) * (e->tab[x][y]) / 2));
			printf("e->coord[%d][%d] : (%d, %d)\n", x, y, ((e->coord)[x][y]).x, ((e->coord)[x][y]).y);
			y++;
		}
		x++;
	}
}
