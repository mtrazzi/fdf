/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:59:17 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/20 19:59:18 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pix	ft_pixel_init(unsigned char a, unsigned char r, \
		unsigned char g, unsigned char b)
{
	t_pix	p;

	p.a = a;
	p.r = r;
	p.g = g;
	p.b = b;
	return (p);
}

t_pix	ft_mix(t_pix p1, t_pix p2)
{
	t_pix p3;

	p3.a = (p1.a + p2.a) / 2;
	p3.r = (p1.r + p2.r) / 2;
	p3.g = (p1.g + p2.g) / 2;
	p3.b = (p1.b + p2.b) / 2;
	return (p3);
}
