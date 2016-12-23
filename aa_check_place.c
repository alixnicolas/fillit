/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_check_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 23:09:21 by aramon            #+#    #+#             */
/*   Updated: 2016/12/22 05:20:59 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utilities.h"


/* count if you can place the four '#' of the piece in the map and assign the 
last position on the map to tmp_j*/
int		get_place(char *map, char *t, int j, int *tmp_j)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	while (map[j] != '\0' && t[index] != '\0')
	{
		if (t[index] == '#')
		{
			if (map[j] == '.')
			{
				*tmp_j = j;
				count++;
			}
		}
		j++;
		index++;
	}
	return (count);
}


/* checks if the piece fits in the map. tmp = the given position and tmp_j = the 
end */
int		check_place(char *map, char *t, int j, int k)
{
	int		count;
	size_t	root;
	int		tmp;
	int		tmp_j;

	root = ft_getroot(ft_strlen(map));
	tmp_j = 0;
	tmp = j;
	/* checks the length of the row and compare it with the length of the first line 
	of the piece */
	if (get_space(map, j, root) < g_valid_b[k])
		return (0);
	/* count if you can place the four '#' of the piece in the map */
	count = get_place(map, t, j, &tmp_j);
	/* because pieces and map are strings, here are series of tests to check with %root 
	if it is still possible to put the piece inside the map. return 0 == not possible */
	if ((tmp + (int)root) % (int)root == ((int)root - 1) && k == 8)
		return (0);
	if (count == 4 && (tmp_j % (int)root) + 1 < g_valid_l[k] && NOTTMPJ(k))
		return (0);
	if (count == 4 && get_countbis(k) > 0 && (tmp + (int)root) % (int)root == 0
			&& ISTMP(k))
		return (0);
	if (count == 4)
		return (1);
	return (0);
}
