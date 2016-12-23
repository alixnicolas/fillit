/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:33:44 by aramon            #+#    #+#             */
/*   Updated: 2016/12/22 04:31:40 by anicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utilities.h"

int			close_file(int fd)
{
	if ((close(fd)) != -1)
		return (1);
	return (0);
}

char		*open_buf(char *file)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*tmp_file;

	tmp_file = ft_strnew(1);
	ret = 0;
	if ((fd = open(file, O_RDONLY)) != -1)
	{
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			buf[ret] = '\0';
			tmp_file = ft_strjoin(tmp_file, buf);
		}
		close_file(fd);
		return (tmp_file);
	}
	close_file(fd);
	return (NULL);
}

int			main(int argc, char **argv)
{
	char	**t;
	char	*file;
	int		nb;

	if (argc < 2 || argc > 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if ((file = open_buf(argv[1])) == NULL)
		ft_putstr("error\n");
	else if ((nb = check_file(file)) == 0)
		ft_putstr("error\n");
	else if ((t = make_array(file, nb)) == NULL)
		ft_putstr("error\n");
	else
		print_map(map_maker(t, nb));
	return (0);
}
