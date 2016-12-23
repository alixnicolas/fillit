/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_make_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:55:46 by aramon            #+#    #+#             */
/*   Updated: 2016/12/22 03:18:48 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utilities.h"

/******************************************************************************
******************************* MAKE ARRAY ************************************
******* Creates an array with all the input pieces by order of appearance 
******* t[0] = first piece. 
*******************************************************************************/

/* BONUS : this function is used by aa_get_data.c to malloc the piece once the
 root of the map is given */

char	*create_new_t(char *t, size_t root)
{
	char	*new_t;
	int		size;

	if ((int)root - 4 < 0)
		size = ft_strlen(t) - (ft_strlen(t) + (((int)root - 4) * 4) + 1);
	else
		size = ft_strlen(t) + (((int)root - 4) * 4) + 1;
	new_t = (char*)malloc(sizeof(char) * size);
	return (new_t);
}

/* 2. creates a string for the piece and removes and counts the number of'\n' */

char	*create_str(char *tmp_piece, int *n_count, int *b_count)
{
	int		index;
	int		start;
	int		end;
	char	*new_piece;

	start = ft_getstart(tmp_piece, '#');
	end = ft_getend(tmp_piece, '#');
	*n_count = 0;
	*b_count = 0;
	new_piece = (char *)malloc(sizeof(char) * ((end - start) + 1));
	index = start;
	while (tmp_piece[index++] == '#')
		(*b_count)++;
	index = 0;
	while (start <= end)
	{
		if (tmp_piece[start] != '\n')
			new_piece[index++] = tmp_piece[start];
		else
			(*n_count)++;
		start++;
	}
	new_piece[index] = '\0';
	return (new_piece);
}

/* 3. checks if the created string is contained in the array of utilities.h */

int		get_piece(char *tmp_piece, int *n_count, int *b_count)
{
	int		k;
	int		i;

	k = 0;
	while (k < 19)
	{
		i = 0;
		while (tmp_piece[i] != '\0' && g_valid_piece[k][i] != '\0' &&
				tmp_piece[i] == g_valid_piece[k][i])
			i++;
		if ((tmp_piece[i] - g_valid_piece[k][i]) == 0)
			if (*n_count == g_valid_n[k] && *b_count == g_valid_b[k])
				return (k);
		k++;
	}
	return (20);
}

/* 1. iterates nb times to create an array of nb piece */

char	**check_tetris(char *file, char **t, int nb, int *ptr_b)
{
	int		count;
	int		index;
	char	*tmp_piece;
	int		n_c;
	int		k;

	count = 1;
	index = 0;
	n_c = 0;
	tmp_piece = (char*)malloc(sizeof(char) * 17);
	tmp_piece[16] = '\0';
	while (count - 1 < nb)
	{
		k = 0;
		while (index < (count * 21) && file[index] != '\0')
			tmp_piece[k++] = file[index++];
		if (get_piece(create_str(tmp_piece, &n_c, ptr_b), &n_c, ptr_b) == 20)
			return (NULL);
		else
			t[count - 1] = create_str(tmp_piece, &n_c, ptr_b);
		count++;
	}
	return (t);
}

char	**make_array(char *file, int nb)
{
	char	**t;
	int		index;
	int		*ptr_b;
	int		b_count;

	b_count = 0;
	ptr_b = &b_count;
	index = 0;
	t = (char**)malloc(sizeof(char*) * nb + 1);
	t = check_tetris(file, t, nb, ptr_b);
	if (t == NULL)
		return (NULL);
	return (t);
}
