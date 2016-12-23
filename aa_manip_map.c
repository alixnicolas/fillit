/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_manip_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 19:21:15 by aramon            #+#    #+#             */
/*   Updated: 2016/12/21 21:17:47 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utilities.h"

char	*put_letter(char *map, int index)
{
	int		j;

	j = 0;
	while (map[j] != '\0')
	{
		if (map[j] == '#')
			map[j] = index + 'A';
		j++;
	}
	return (map);
}

char	*remove_letter(char *map, int letter)
{
	int		j;

	j = 0;
	while (map[j] != '\0')
	{
		if (map[j] == letter + 'A')
			map[j] = '.';
		j++;
	}
	return (map);
}

int		get_j(char *map, int index)
{
	int j;

	j = 0;
	while (map[j] != index + 'A' && map[j] != '\0')
		j++;
	return (j);
}

char	*put_piece(char *map, char *tetriminos, int j, int index)
{
	int		l;

	l = 0;
	while (tetriminos[l] != '\0')
	{
		if (map[j] != '.')
		{
			l++;
			j++;
		}
		else
		{
			map[j] = tetriminos[l];
			j++;
			l++;
		}
	}
	map = put_letter(map, index);
	return (map);
}
