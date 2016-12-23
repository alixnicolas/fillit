/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:37:42 by aramon            #+#    #+#             */
/*   Updated: 2016/12/21 21:33:29 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utilities.h"

/* function that calls the solver and make the map bigger if the solver does not
 succeed */
char		*map_maker(char **t, int nb)
{
	char	*map;
	int		n;

	map = make_map(get_map_size(nb));
	n = nb;
	while ((map = feel_map(t, map, n)) == NULL)
	{
		free(map);
		nb++;
		map = make_map(get_map_size(nb));
	}
	return (map);
}

void		print_map(char *map)
{
	int		sqr;
	int		count;
	int		i;

	sqr = ft_getroot(ft_strlen(map));
	count = 0;
	i = 0;
	while (map[i] != '\0')
	{
		while (((i - (sqr * count)) < sqr) && map[i] != '\0')
		{
			ft_putchar(map[i]);
			i++;
		}
		ft_putchar('\n');
		count++;
	}
}

int			get_map_size(int nb)
{
	int		sqr;
	int		rslt;
	int		tmp;

	rslt = nb * 4;
	sqr = 1;
	tmp = 1;
	while (sqr < rslt)
	{
		tmp++;
		sqr = tmp * tmp;
	}
	return (sqr);
}

/* this is the function that creates the map by filling a string with '.' */
char		*make_map(int sqr)
{
	char	*map;
	int		tmp;

	tmp = 0;
	map = (char*)malloc(sizeof(char) * sqr + 1);
	map[sqr] = '\0';
	while (tmp < sqr)
	{
		map[tmp] = '.';
		tmp++;
	}
	return (map);
}
