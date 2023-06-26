/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:16:52 by rimarque          #+#    #+#             */
/*   Updated: 2023/06/24 19:46:18 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_pixel_put(t_data	*img, int x, int y, int color)
{
	char	*dst;
	int	offset;

	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	dst = img->addr + offset;
	*(unsigned int*)dst = color;
}

void draw_square(t_data *img, int x, int y, int space)
{
	int y2 = y;
	int x2 = x;
	while (y < space + y2)
	{
		ft_pixel_put(img, x, y, 0x00FF0000);
		ft_pixel_put(img, x + space, y, 0x00FF0000);
		y++;
	}
	while (x < space + x2)
	{
		ft_pixel_put(img, x, y, 0x00FF0000);
		ft_pixel_put(img, x, y - space, 0x00FF0000);
		x++;
	}
	/*
	int y2 = y;
	while(y < space)
	{
		printf("while y:\ny: %i\n", y);
		printf("x: %i\n", x);
		ft_pixel_put(img, x, y, 0x00FF0000);
		ft_pixel_put(img, space, y, 0x00FF0000);
		y++;
	}

	while(x < space)
	{
		printf("while x:\ny: %i\n", y);
		printf("x: %i\n", x);
		ft_pixel_put(img, x, y2, 0x00FF0000);
		ft_pixel_put(img, x, space, 0x00FF0000);
		x++;
	}*/
}


int main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init(); //establish a connection to the correct graphical system
		//and returns a pointer to the location of our current MLX instance
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "hello world"); //return a pointer to the window we are creating
	//             (pointer_init, width, height, title)
	//colunas;
	//linhas;

	//draw_square(&img, 5, 5, 500);
	ft_pixel_put(&img, 1736, 700, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 705, 285); //(1920 - 510)/2 = 705; (1080 - 510)/2 = 285
	//(                       ,cordenadas de onde queres meter a imagem)
	mlx_hook(vars.win, 2, 1L<<0, key_handler, &vars);
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_loop(vars.mlx); //iniciate the window
	//DESTROY window
	//DESTROY init
}

