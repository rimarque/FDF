/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:36:14 by rimarque          #+#    #+#             */
/*   Updated: 2023/07/01 19:46:13 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	close_win(t_list *map)
{
	free_stack(map);
	mlx_destroy_image(map->init->mlx_ptr, map->img->img_ptr);
	mlx_destroy_window(map->init->mlx_ptr, map->init->win_ptr);
	mlx_destroy_display(map->init->mlx_ptr);
	free(map->init->mlx_ptr);
	exit(0);
}
int	key_handler(int keycode, t_list *map)
{
	if (keycode == ESC)
		close_win(map);
	return(0);
}
void	set_graphic(t_vars	*init, char* file, t_data *img, t_list *map)
{
	init->mlx_ptr = mlx_init();
	init->win_ptr = mlx_new_window(init->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, file);
	img->img_ptr = mlx_new_image(init->mlx_ptr, map->dst_width, map->dst_height);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length,
		&img->endian);
	img->x_init = (WIN_WIDTH - map->dst_width) / 2;
	img->y_init = (WIN_HEIGHT - map->dst_height) / 2;
	map->img = img;
	map->init = init;
}

int	main(int argc, char **argv)
{
	t_list	map;
	t_vars	init;
	t_data	img;

	create_stack(&map);
	if (argc != 2 || ft_strcmp(argv[1] + ft_strclen(argv[1], '.'), ".fdf"))
	{
		ft_printf("fdf: INSERT <file.fdf>\n");
		return(0);
	}
	read_map(&map, argv[1]);
	set_graphic(&init, argv[1], &img, &map);
	draw_map(map, img);
	mlx_put_image_to_window(init.mlx_ptr, init.win_ptr, img.img_ptr, img.x_init, img.y_init);
	mlx_hook(init.win_ptr, 2, 1L<<0, key_handler, &map);
	mlx_hook(init.win_ptr, 17, 0, close_win, &map);
	mlx_loop(init.mlx_ptr);
	return(0);
}
