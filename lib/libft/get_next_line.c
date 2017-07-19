/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 11:58:27 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/19 14:50:19 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	assign_and_do(char **dest, char *src, int *go)
{
	if (!(*go))
		return ;
	if (src != NULL)
		*dest = src;
	*go = (src != NULL);
	return ;
}

char	*get_line_aux(char **line, char *tmp)
{
	int		n;
	char	*after;

	n = 0;
	while (tmp[n] != '\n')
		n++;
	tmp[n] = '\0';
	if (!(*line = ft_strdup(tmp)))
		return (NULL);
	if (!(after = ft_strdup(tmp + n + 1)))
		return (NULL);
	return (after);
}

char	*get_buffer(const int fd, int *over, int *go)
{
	char	*buff;
	int		ret;
	char	*result;
	char	*tmp;

	assign_and_do(&buff, ft_strnew(BUFF_SIZE), go);
	assign_and_do(&result, ft_strnew(BUFF_SIZE), go);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && !ft_strchr(buff, '\n'))
	{
		assign_and_do(&tmp, ft_strdup(result), go);
		free(result);
		buff[ret] = '\0';
		assign_and_do(&result, ft_strjoin(tmp, buff), go);
		free(tmp);
	}
	buff[ret] = '\0';
	assign_and_do(&tmp, ft_strdup(result), go);
	free(result);
	assign_and_do(&result, ft_strjoin(tmp, buff), go);
	if (!(*over = (ret == 0)) && (ret == -1))
		return (NULL);
	free(tmp);
	free(buff);
	return (result);
}

int		get_line(const int fd, char **line, int *over, int *go)
{
	static char	*tmp = "";
	char		*to_free;
	char		*buffer;
	char		*fusion;

	if (ft_strchr(tmp, '\n'))
	{
		to_free = tmp;
		assign_and_do(&tmp, get_line_aux(line, tmp), go);
		free(to_free);
		return (*go);
	}
	if (!(buffer = get_buffer(fd, over, go)))
		return ((*go = 0));
	assign_and_do(&fusion, ft_strjoin(tmp, buffer), go);
	if (ft_strchr(fusion, '\n'))
		assign_and_do(&tmp, get_line_aux(line, fusion), go);
	else
	{
		assign_and_do(line, ft_strdup(fusion), go);
		tmp = "";
	}
	free(buffer);
	free(fusion);
	return (*go);
}

int		get_next_line(const int fd, char **line)
{
	int			x;
	int			y;

	x = 0;
	y = 1;
	if (!(get_line(fd, line, &x, &y)))
		return (-1);
	if (x && **line == '\0')
		return (0);
	return (1);
}
