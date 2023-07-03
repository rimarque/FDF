/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:28:43 by rimarque          #+#    #+#             */
/*   Updated: 2023/07/03 22:53:11 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_node	*create_point(int x, int y, int z, t_list map)
{
	t_node	*point;

	point = malloc(sizeof(t_node));
	if (!point)
		return (NULL);
	point->src_x = x;
	point->src_y = y;
	x = x * map.edge;
	y = y * map.edge;
	z *= map.z_scale;
	point->dst_x = ft_proj_x(x, y, z);
	point->dst_y = ft_proj_y(x, y, z);
	return (point);
}

void	set_coords(t_list	*map)
{
	int		y;
	int		x;
	t_node	*point;

	y = 0;
	while (y <= map->src_y_max)
	{
		x = 0;
		while (x <= map->src_x_max)
		{
			point = create_point(x, y, ft_atoi(map->matrix[y][x]), *map);
			insert_last(map, point);
			x++;
		}
		y++;
	}
}

void	offset(t_list *map)
{
	int	offset;

	offset = offset_x(*map);
	if (offset > 0)
		increase_x(map, offset);
	offset = offset_y(*map);
	if (offset > 0)
		increase_y(map, offset);
}

void	create_map(t_list *map)
{
	set_scale(map);
	set_coords(map);
	ft_free_matrix(&map->matrix);
	offset(map);
}
