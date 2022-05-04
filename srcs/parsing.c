/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:21 by hoh               #+#    #+#             */
/*   Updated: 2022/04/19 15:32:22 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*parsing(char *map_ber)
{
	int		fd;
	int		width;
	char	*pars;
	char	*map;

	map = 0;
	fd = open(map_ber, O_RDONLY);
	pars = get_next_line(fd);
	width = gnl_strlen(pars);
	map = gnl_strjoin(map, pars);
	free(pars);
	while (pars)
	{
		pars = get_next_line(fd);
		width = gnl_strlen(pars);
		map = gnl_strjoin(map, pars);
		free(pars);
	}
	return (map);
}
