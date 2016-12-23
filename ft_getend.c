/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 00:32:43 by anicolas          #+#    #+#             */
/*   Updated: 2016/12/09 00:45:15 by anicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_getend(char *str, char c)
{
	int		end;

	end = ft_strlen(str);
	while (str[end] != c)
		end--;
	return (end);
}
