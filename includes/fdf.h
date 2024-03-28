/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:59:05 by rimarque          #+#    #+#             */
/*   Updated: 2024/03/28 23:26:36 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <errno.h>
# include <math.h>
# include "../libftx/includes/libft.h"
# include "../libftx/includes/ft_printf.h"
# include "../libftx/includes/get_next_line.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

# define ESC 65307
# define COLOR 0x00AAFF
# define ANGLE 120
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define SCALE 0.6

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	int		x_init;
	int		y_init;
}t_data;

typedef struct s_node
{
	struct s_node		*prev;
	int					src_x;
	int					src_y;
	int					dst_x;
	int					dst_y;
	struct s_node		*next;
}t_node;

typedef struct s_list
{
	t_node			*head;
	int				size;
	int				edge;
	char			***matrix;
	int				src_x_max;
	int				src_y_max;
	float			z_scale;
	t_data			*graphic;
}t_list;

typedef struct s_line
{
	float	dif_x;
	float	dif_y;
	float	n_step;
	float	x_step;
	float	y_step;
	float	x;
	float	y;
}t_line;

//AUX MAP
void	create_stack(t_list *stack);
void	insert_last(t_list *stack, t_node *new);
void	free_stack(t_list *stack);
void	increase_x(t_list *map, float offset);
void	increase_y(t_list *map, float offset);

//PARSE MAP
void	parse_map(t_list *map, char *file);

//CREATE MAP
void	create_map(t_list *map);

//SET VARS
void	set_max(t_list *map, int y);
void	set_scale(t_list *map);
void	set_graphic(t_list *map, t_data	*graphic, char *file);

//AUX X MAX
int		small_line(char	***matrix, int y);

//SCALE
void	set_edge(t_list *map);
void	set_z_scale(t_list *map);

//MATH
float	get_max(float a, float b);
int		ft_proj_x(int x, int y, long long z);
int		ft_proj_y(int x, int y, long long z);
int		offset_x(t_list map);
int		offset_y(t_list map);

//MAP LIM
int		biggest_x(t_list stack);
int		biggest_y(t_list stack);
int		smallest_x(t_list stack);
int		smallest_y(t_list stack);

//DRAW MAP
void	draw_map(t_list map, t_data img);

#endif
