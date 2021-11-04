/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheadles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:37:06 by wheadles          #+#    #+#             */
/*   Updated: 2021/11/03 18:37:14 by wheadles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str++ == (char)c)
			return ((char *)str - 1);
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char *buff, char *rb)
{
	char	*z;
	size_t	i;

	if (!buff)
	{
		buff = (char *)malloc(sizeof(char));
		buff[0] = '\0';
	}
	if (!buff || !rb)
		return (NULL);
	z = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(rb) + 1));
	if (!z)
	{
		free(buff);
		return (NULL);
	}
	i = -1;
	if (buff)
		while (buff[++i])
			z[i] = buff[i];
	free(buff);
	while (*rb)
		z[i++] = *rb++;
	z[i] = '\0';
	return (z);
}

char	*get_line(char *buff)
{
	char	*s;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		s[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		s[i] = buff[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*new_buff(char *buff)
{
	int		i;
	char	*z;
	int		j;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	z = (char *)malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!z)
		return (NULL);
	i++;
	j = 0;
	while (buff[i])
		z[j++] = buff[i++];
	z[j] = '\0';
	free(buff);
	return (z);
}
