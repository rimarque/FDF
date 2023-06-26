/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:36:14 by rimarque          #+#    #+#             */
/*   Updated: 2023/06/26 23:33:01 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
//criat funcao para inicializar as variaveis
int	close_win(t_vars *init)
{
	mlx_destroy_window(init->mlx, init->win);
	exit(0);
}
int	key_handler(int keycode, t_vars *init)
{
	if (keycode == ESC)
		close_win(init);
	return(0);
}
void	set_graphic(t_vars	*init, char* file, t_data *data, t_list map)
{
	init->mlx = mlx_init();
	init->win = mlx_new_window(init->mlx, 1920, 1080, file);
	//data->img = mlx_new_image(init->mlx, map.dst_width, map.dst_height);
	data->width = map.dst_width;
	data->height = map.dst_height;
	data->img = mlx_new_image(init->mlx, map.dst_width, map.dst_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
		&data->endian);
}

int	main(int argc, char **argv)
{
	t_list	map;
	t_vars	init;
	t_data	data;

	create_stack(&map);
	if (argc != 2)
		return(0);
	read_map(&map, argv[1]); //se descomentar n abre janela
	set_graphic(&init, argv[1], &data, map);
	/*init.mlx = mlx_init();
	init.win = mlx_new_window(init.mlx, 1920, 1080, argv[0]);
	img.img = mlx_new_image(init.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);*/
	//printf("%2.f, %2.f\n", map.dst_width , map.dst_height);
	draw_map(map, data);
	int x = (1920 - map.dst_width) / 2;
	int y = (1080 - map.dst_height) / 2;
	mlx_put_image_to_window(init.mlx, init.win, data.img, x, y); //(1920 - 510)/2 = 705; (1080 - 510)/2 = 285
	mlx_hook(init.win, 2, 1L<<0, key_handler, &init);
	mlx_hook(init.win, 17, 0, close_win, &init);
	mlx_loop(init.mlx);
	return(0);
}
