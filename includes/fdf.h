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

typedef struct	s_data
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x_init;
	int		y_init;
}t_data;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
}t_vars;

typedef struct s_node
{
	struct s_node		*prev;
	int					src_x;
	int					src_y;
	int					src_z;
	int					dst_x;
	int					dst_y;
	struct s_node		*next;
}t_node;

/*typedef struct s_limits
{
	struct t_node	*point_a;
	struct t_node	*point_b;
	struct t_node	*point_c;
	struct t_node	*point_d;
}t_limits;*/

typedef struct s_list
{
	t_node			*head;
	int				edge;
	int				src_x_max;
	int				src_y_max;
	int				dst_width;
	int				dst_height;
	float			z_scale;
	//t_data			img;
	//struct t_limits *limits;
	int				size;
	t_data			*img;
	t_vars			*init;
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

//LIST
void	create_stack(t_list *stack);
void	insert_last(t_list *stack, t_node *new);
void	free_stack(t_list *stack);
void	increase_x(t_list *map, float offset);
void	increase_y(t_list *map, float offset);

//READ MAP
void	read_map(t_list *map, char *file);
void	print_map(char **map);
void	set_scale(t_list *map);

//MATH
int	ft_proj_x(int x, int y, long long z);
//int	ft_proj_x(int x, int y);
int	ft_proj_y(int x, int y, long long z);
void	set_z_scale(t_list *map, char ***matrix);

//void	put_pixel_img(t_data img, float x, float y, int color);
void	put_pixel_img(t_data img, int x, int y, int color);
void	draw_map(t_list map, t_data img);
//void	draw_map(t_list map);

//OFFSET
int	calc_offset_x(t_list map);
int	calc_offset_y(t_list map);

int	biggest_x(t_list stack);
int	biggest_y(t_list stack);
int	smallest_x(t_list stack);
int	smallest_y(t_list stack);

int	count_num(char **array);
int	small_line(char	***matrix, int y);
int	smallest_nbr(int *numbers, int y);

#endif
