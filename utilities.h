/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:54:00 by aramon            #+#    #+#             */
/*   Updated: 2016/12/22 04:50:41 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H
# define BUF_SIZE 545
# define ISCHARCORRECT(x) (x != '.' && x != '\n' && x != '#' && x != '\0')
# define NOTTMPJ(x) (x!=1 && x!=7 && x!=8 && x!=9 && x!=14 && x!=15)
# define ISTMP(x) (x==3 || x==4 || x==10 || x==11 || x==14 || x==15)
# include <fcntl.h>

static char *g_valid_piece[19] = {"#...#...##", "###.#", "##...#...#", "#.###",
	"#...#..##", "###...#", "#...###", "##..#...#", "#...##..#", "###..#",
	"#..##...#", "#..###", "#...##...#", "##...##", "#..##..#", "##.##",
	"#...#...#...#", "##..##", "####"};

static int g_valid_n[19] = {2, 1, 2, 1, 2, 1, 1, 2, 2, 1, 2, 1, 2, 1, 2, 1, 3,
	1, 0};

static int g_valid_l[19] = {2, 3, 2, 3, 2, 3, 3, 2, 2, 3, 2, 3, 2, 3, 2, 3, 1,
	2, 4};

static int g_valid_b[19] = {1, 3, 2, 1, 1, 3, 1, 2, 1, 3, 1, 1, 1, 2, 1, 2, 1,
	2, 4};

int		check_file(char *str);
int		close_file(int fd);
int		give_number(char *file);
char	*open_buf(char *file);
char	**check_tetris(char *file, char **t, int nb, int *ptr_b);
char	**make_array(char *file, int nb);
int		get_piece(char *tmp_piece, int *n_count, int *b_count);
char	*create_str(char *tmp_piece, int *n_count, int *b_count);
char	*make_map(int sqr);
int		get_k(char *t);
char	*put_letter(char *map, int index);
char	*remove_letter(char *map, int letter);
char	*solve_map(char *map, char **t, size_t root, int nb);
char	*feel_map(char **t, char *map, int nb);
int		get_map_size(int nb);
int		get_countbis(int index);
int		get_space(char *map, int j, size_t root);
char	*get_dyn(char *t, size_t root);
int		check_place(char *map, char *t, int j, int k);
int		get_place(char *map, char *t, int j, int *tmp_j);
char	*put_piece(char *map, char *tetriminos, int j, int index);
int		get_j(char *map, int index);
void	print_map(char *map);
char	*map_maker(char **t, int nb);
char	*create_new_t(char *t, size_t root);
int		backtrack(char *map, int j, int *index, int *count);
int		first_check(int nb, int *index, int *count);

#endif
