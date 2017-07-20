/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:55:44 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/20 19:55:45 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_pt(int x, int y, t_pix pix)
{
	t_point	t;

	t.x = x;
	t.y = y;
	t.pix = pix;
	return (t);
}
