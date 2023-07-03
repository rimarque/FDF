/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:32:37 by rimarque          #+#    #+#             */
/*   Updated: 2023/07/03 22:54:00 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_max(t_list *map, int y)
{
	map->src_y_max = y - 1;
	map->src_x_max = small_line(map->matrix, y) - 1;
}

void	set_scale(t_list *map)
{
	set_edge(map);
	set_z_scale(map);
}

void	set_graphic(t_list *map, t_data	*graphic, char *file)
{
	graphic->img_width = biggest_x(*map) + 1;
	graphic->img_height = biggest_y(*map) + 1;
	graphic->mlx_ptr = mlx_init();
	graphic->win_ptr = mlx_new_window(graphic->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, file);
	graphic->img_ptr = mlx_new_image(graphic->mlx_ptr, graphic->img_width,
			graphic->img_height);
	graphic->addr = mlx_get_data_addr(graphic->img_ptr,
			&graphic->bits_per_pixel,
			&graphic->line_length, &graphic->endian);
	graphic->x_init = (WIN_WIDTH - graphic->img_width) / 2;
	graphic->y_init = (WIN_HEIGHT - graphic->img_height) / 2;
	map->graphic = graphic;
}
