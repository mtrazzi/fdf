/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 12:45:33 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/05/27 12:57:22 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ans;

	ans = (char *)s;
	i = 0;
	while (ans[i] && ans[i] != c)
		i++;
	if (ans[i] == c)
		return (ans + i);
	return (NULL);
}
