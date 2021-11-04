/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheadles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:36:41 by wheadles          #+#    #+#             */
/*   Updated: 2021/11/03 18:36:45 by wheadles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_buff(int fd, char *buff)
{
	char	*rb;
	int		rb_bytes;

	rb_bytes = 1;
	rb = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!rb)
		return (NULL);
	while (!ft_strchr(buff, '\n') && rb_bytes != 0 )
	{
		rb_bytes = read(fd, rb, BUFFER_SIZE);
		if (rb_bytes == -1)
		{
			free(rb);
			return (NULL);
		}
		rb[rb_bytes] = '\0';
		buff = ft_strjoin(buff, rb);
	}
	free(rb);
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*line_to_return;
	static char	*buff;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	buff = read_buff(fd, buff);
	if (!buff)
		return (NULL);
	line_to_return = get_line(buff);
	buff = new_buff(buff);
	return (line_to_return);
}
