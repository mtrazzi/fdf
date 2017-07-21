/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:19:33 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/21 12:29:33 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(EXIT_FAILURE);
	else if (keycode == 8 && !e->o.clean)
		ft_clean(e);
	else if (keycode == 8)
	{
		ft_clean(e);
		e->o.clean = 0;
		draw(e);
	}
	else if (keycode == 123)
		ft_move(e, -1);
	else if (keycode == 124)
		ft_move(e, 1);
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

void	ft_move(t_env *e, int move)
{
	ft_clean(e);
	if ((e->o.cursor > 1 && move == -1) || (e->o.cursor < e->o.ac - 1 && move == 1))
		e->o.cursor += move;
	e->o.clean = 0;
	draw(e);
}
