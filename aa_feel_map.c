/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_feel_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:37:51 by aramon            #+#    #+#             */
/*   Updated: 2016/12/22 04:07:02 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utilities.h"

int		first_check(int nb, int *index, int *count)
{
	/* nb = number of piece */
	if (nb == 1)
		return (-1);
	if (*index != 0)
		(*index)--;
	*count = *index + 1;
	return (0);
}

int		get_position(char *map, int j, char *t, size_t root)
{
	char	*tetriminos;

	/* creates a dynamic piece according the size of the map to check if it
	 can be place (aa_get_data.c) */
	tetriminos = get_dyn(t, root);
	while (check_place(map, tetriminos, j, get_k(t)) == 0 && map[j] != '\0')
		j++;
	return (j);
}

int		backtrack(char *map, int j, int *index, int *count)
{
	if (map[j] == '\0' && *index == 0)
		return (-1);
	if (map[j] == '\0')
	{
		(*count)--;
		(*index)--;
	}
	else
		*count = 0;
	return (1);
}

/* no recursion ;) */

char	*solve_map(char *map, char **t, size_t root, int nb)
{
	int		index;
	int		j;
	int		count;

	index = -1;
	while (t[++index])
	{
		/* goes to the begining of the map (it can gets dynamic if instead of 0 you put 
		a variable), checks if there is enough space for the piece and return the 
		position where the letter can replace the '.' */
		j = get_position(map, 0, t[index], root);
		/* this condition == if there is not enough space for the piece*/
		if (map[j] == '\0')
		{
			/* checks if there is not just one piece in the array and decrement index 
			to move the previous piece one '.' after + creates the iterator of the next
			 loop */  
			if (first_check(nb, &index, &count) == -1)
				return (NULL);
			/* moves the previous piece one '.' after (== + 1) on the map after removing its 
			relative letter on the map (current file + aa_manip_map.c) */ 
			while (count > 0)
			{
				j = get_j(map, index) + 1;
				j = get_position(remove_letter(map, index), j, t[index], root);
				/* if backtrack returns -1 == the very first piece of the array can't be 
				place and the map has to get bigger 
				   backtrack assign 0 to count if the piece can be placed - end of the loop
				   backtrack decrement index (and move the previous piece of the 
				   previous piece) if the current previous piece can't be placed */ 
				if (backtrack(map, j, &index, &count) == -1)
					return (NULL);
			}
		}
		/*assigns letter in the map (aa_manip_map.c) */
		map = put_piece(map, get_dyn(t[index], root), j, index);
		/* returns the mp to print it*/
		if (index + 1 >= nb)
			return (map);
	}
	return (NULL);
}

/* Yes, this is the big part, if the solver returns NULL the map will get bigger */

char	*feel_map(char **t, char *map, int nb)
{
	size_t	root;

	root = ft_getroot(ft_strlen(map));
	if ((map = solve_map(map, t, root, nb)) == NULL)
		return (NULL);
	else
		return (map);
}
