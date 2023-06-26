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

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	float			width;
	float			height;
}t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}t_vars;

typedef struct s_node
{
	struct s_node		*prev;
	int					src_x;
	int					src_y;
	float				dst_x;
	float				dst_y;
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
	float			edge;
	int				src_x_max;
	int				src_y_max;
	float			dst_width;
	float			dst_height;
	//t_data			img;
	//struct t_limits *limits;
	int				size;
}t_list;

/*typedef enum keycodes
{
	ESC = 65307,
}t_keys;*/

//LIST
void	create_stack(t_list *stack);
void	insert_last(t_list *stack, t_node *new);

//READ MAP
void	read_map(t_list *map, char *file);
void	print_map(char **map);

//MATH
float	ft_proj_x(int x, int y, long long z);
float	ft_proj_y(int x, int y, long long z);

void	draw_map(t_list map, t_data img);
//void	draw_map(t_list map);
#endif
