#ifndef FDF_H
# define FDF_H

# include <errno.h>
# include <math.h>
# include "../libftx/includes/libft.h"
# include "../libftx/includes/ft_printf.h"
# include "../libftx/includes/get_next_line.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}t_vars;

typedef struct s_node
{
	struct t_node		*prev;
	int					src_x;
	int					src_y;
	float				dst_x;
	float				dst_y;
	struct t_node		*next;
}t_node;

typedef struct s_list
{
	struct t_node *head;
	float			edge;
	int				angle;
	int				size;
}t_list;

typedef enum keycodes
{
	ESC = 65307,
}t_keys;

//LIST
void	create_stack(t_list *stack);

//READ MAP
void	read_map(t_list *map, char *file);
void	print_map(char **map);

//MATH
float	ft_proj_x(int x, int y, long long z, int a);
float	ft_proj_y(int x, int y, long long z, int a);
#endif
