/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:44:00 by aramon            #+#    #+#             */
/*   Updated: 2016/12/22 03:46:41 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utilities.h"

int		give_number(char *file)
{
	int		i;
	int		count_n;
	int		count_p;
	int		nbr_piece;

	i = 0;
	count_n = 0;
	count_p = 0;
	nbr_piece = 0;
	while (file[i] != '\0')
	{
		if (ISCHARCORRECT(file[i]))
			return (0);
		if (file[i] == '\n' && (file[i - 1] == '\n' || file[i + 1] == '\0'))
			if (count_p % 12 != 0)
				return (0);
		if (file[i] == '.')
			count_p++;
		if (file[i] == '\n')
			count_n++;
		i++;
	}
	if (count_n % 5 != 4)
		return (0);
	return (count_n / 5 + 1);
}

int		check_file(char *file)
{
	int		nb;

	if ((nb = give_number(file)) == 0 || nb > 26)
		return (0);
	return (nb);
}
