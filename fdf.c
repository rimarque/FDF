/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:36:14 by rimarque          #+#    #+#             */
/*   Updated: 2023/07/03 21:34:39 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	close_win(t_list *map)
{
	free_stack(map);
	mlx_destroy_image(map->graphic->mlx_ptr, map->graphic->img_ptr);
	mlx_destroy_window(map->graphic->mlx_ptr, map->graphic->win_ptr);
	mlx_destroy_display(map->graphic->mlx_ptr);
	free(map->graphic->mlx_ptr);
	exit(0);
}

int	key_handler(int keycode, t_list *map)
{
	if (keycode == ESC)
		close_win(map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	map;
	t_data	graphic;

	create_stack(&map);
	if (argc != 2 || ft_strcmp(argv[1] + ft_strclen(argv[1], '.'), ".fdf"))
	{
		ft_printf("fdf: INSERT <file.fdf>\n");
		return (0);
	}
	parse_map(&map, argv[1]);
	create_map(&map);
	set_graphic(&map, &graphic, argv[1]);
	draw_map(map, graphic);
	mlx_put_image_to_window(graphic.mlx_ptr, graphic.win_ptr, graphic.img_ptr,
		graphic.x_init, graphic.y_init);
	mlx_hook(graphic.win_ptr, 2, 1L << 0, key_handler, &map);
	mlx_hook(graphic.win_ptr, 17, 0, close_win, &map);
	mlx_loop(graphic.mlx_ptr);
	return (0);
}
