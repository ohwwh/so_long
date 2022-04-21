/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:04:21 by ohw               #+#    #+#             */
/*   Updated: 2022/03/14 20:53:07 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

size_t	ft_strnlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	if (str && str[len] == '\n')
		len ++;
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = 0;
		i ++;
	}
}

char	*ft_strndup(char *src, size_t n, int flag)
{
	size_t	i;
	char	*ret;

	if (src && !*src)
	{
		if (flag)
			free(src);
		return (0);
	}	
	ret = (char *)malloc((n + 1) * sizeof(char));
	if (ret)
	{
		i = 0;
		while (src && i < n)
		{
			ret[i] = src[i];
			i ++;
		}
		ret[i] = '\0';
		if (flag)
			free(src);
		return (ret);
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s ++;
	}
	if (!c)
		return ((char *)s);
	return (0);
}
