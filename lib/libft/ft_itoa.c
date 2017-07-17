/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 16:41:28 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/05/29 18:38:45 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t			num_dig(int n)
{
	size_t m;

	m = 1;
	while (n > 9)
	{
		n /= 10;
		m++;
	}
	return (m);
}

static char				*ft_itoa_aux(int n, char *s, int len, int i)
{
	while (--len >= 0)
	{
		s[len] = '0' + n % 10;
		n /= 10;
	}
	return (s - i);
}

char					*ft_itoa(int n)
{
	char *tmp;

	if (n == -2147483648)
	{
		if ((tmp = ft_strnew(sizeof(char) * 11)) == NULL)
			return (NULL);
		return (ft_strncpy(tmp, "-2147483648", 11));
	}
	if (n < 0)
	{
		if ((tmp = ft_strnew(num_dig(-n) + 1)) == NULL)
			return (NULL);
		tmp[0] = '-';
		return (ft_itoa_aux(-n, tmp + 1, num_dig(-n), 1));
	}
	if ((tmp = ft_strnew(sizeof(char) * num_dig(n))) == NULL)
		return (NULL);
	return (ft_itoa_aux(n, tmp, num_dig(n), 0));
}
