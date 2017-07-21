/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:19:33 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/21 16:16:26 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(EXIT_FAILURE);
	else if (keycode == 8 && !e->o.clean)
	{
		e->o.clean = 1;
		ft_clean(e);
	}
	else if (keycode == 8)
	{
		ft_clean(e);
		e->o.clean = 0;
		draw(e);
	}
	else if (keycode == 123 || keycode == 124)
		ft_move(e, (keycode == 123 ? -1 : 1));
	else if (keycode == 126 || keycode == 125)
		ft_scale(e, keycode);
	else if (keycode == 0 || keycode == 2 || keycode == 13 || keycode == 1 || keycode == 49)
	{
		if (keycode == 0 || keycode == 2)
			e->pad = e->pad + keycode - 1;
		if (keycode == 1 || keycode == 13)
			e->h = e->h - (keycode - 7) * 6;
		if (keycode == 49)
			e->o.color = 1 - e->o.color;
		ft_clean(e);
		draw(e);
	}
	else
	{
		ft_putnbr(keycode);
		ft_putchar('\n');
	}
	return (0);
}

void	ft_move(t_env *e, int move)
{
	ft_clean(e);
	e->scale = 1;
	if ((e->o.cursor > 1 && move == -1) || (e->o.cursor < e->o.ac - 1 && move == 1))
		e->o.cursor += move;
	e->o.clean = 0;
	draw(e);
}

void	ft_loading(t_env *e, int n)
{
	if (n)
		ft_straight_line(ft_pt(1500, 800, e->pix), ft_pt(1500, 900, e->pix), 0x00FFFFFF, e);
	else
		ft_straight_line(ft_pt(1500, 800, e->pix), ft_pt(1500, 800, e->pix), 0x00000000, e);
}

void	ft_scale(t_env *e, int keycode)
{
	if (e->scale > 1 && keycode == 126)
		e->scale = e->scale * 2;
	if (keycode == 125)
		e->scale = e->scale / 2;
	ft_clean(e);
	draw(e);
}
