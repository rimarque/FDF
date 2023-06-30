/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:46:24 by rimarque          #+#    #+#             */
/*   Updated: 2023/06/30 19:10:42 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	put_pixel_img(t_data img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *) dst = color;

}
void	draw_line(t_node point_a, t_node point_b, t_data img) //as cordenadas serao literais, por isso temos de usar o edge para fazer as linhas NAO E POSSIVEL: USAR O EDGE AO FAZER A TRANSFORMACAO PARA DST_X E DST_Y
{
	float		dif_x;
	float		dif_y;
	float		mod_dif_x;
	float		mod_dif_y;
	float		n_step;
	float	x_step;
	float	y_step;
	float		x;
	float		y;

	dif_x = point_b.dst_x - point_a.dst_x;
	dif_y = point_b.dst_y - point_a.dst_y;
	if (dif_x < 0)
		mod_dif_x = dif_x * -1;
	else
		mod_dif_x = dif_x;
	if (dif_y < 0)
		mod_dif_y = dif_y * -1;
	else
		mod_dif_y = dif_y;
	//printf("DRAW LINE\n");
	//printf("A:(%d, %d) (%f, %f); ", point_a.src_x, point_a.src_y, point_a.dst_x, point_a.dst_y);
	//printf("B:(%d, %d) (%f, %f)\n", point_b.src_x, point_b.src_y, point_b.dst_x, point_b.dst_y);
	//printf("dif x: %f, dif y: %f\n", dif_x, dif_y);
	if (mod_dif_x >= mod_dif_y) //step e igual a maior distancia
		n_step = mod_dif_x;
	else
		n_step = mod_dif_y;
	x_step = dif_x / n_step;
	y_step = dif_y / n_step;
	x = point_a.dst_x;
	y = point_a.dst_y;
	//printf("step: %f, x_init: %f, y_init: %f, x: %f, y: %f\n", step, x_init, y_init, x, y);
	int i = 0;
	//printf("x: %f, y: %f\n", x, y);
	/*if (point_b.dst_x == map.head->prev->dst_x)
	{
		printf("oi");
		put_pixel_img(img, point_b.dst_x, point_b.dst_y, COLOR);
	}*/
	//printf("x: %f, y: %f\n", x, y);
	while (i <= n_step)
	{
		put_pixel_img(img, x, y, COLOR);
		//printf("x: %f, y: %f\n", x, y);
		x += x_step;
		y += y_step;
		i++;
	}
	//ft_put_pixel(img, x, y, COLOR);
}

void	draw_map(t_list map, t_data img)
{
	t_node	*point_a;
	t_node	*point_b;

	point_a = map.head;
	//int count = 0;

	/*size_t n = 18;
	while(n--)
	{
		point_a = point_a->next;
	}*/
	while(point_a != map.head->prev)
	//while(count++ < 1)
	{
		point_b = point_a->next;
		if (point_a->src_x < map.src_x_max)
		{
			//printf("HORIZONTAL: ");
			//printf("A:(%d, %d) (%2.f, %2.f); ", point_a->src_x, point_a->src_y, point_a->dst_x, point_a->dst_y);
			//printf("B:(%d, %d) (%2.f, %2.f)\n", point_b->src_x, point_b->src_y, point_b->dst_x, point_b->dst_y);
			draw_line(*point_a, *point_b, img);
		}
		while(point_a->src_x != point_b->src_x && point_b != map.head->prev)
			point_b = point_b->next;
		if (point_a->src_y < map.src_y_max || point_b != map.head->prev)
		{
			//printf("VERTICAL: ");
			//printf("A:(%d, %d) (%2.f, %2.f); ", point_a->src_x, point_a->src_y, point_a->dst_x, point_a->dst_y);
			//printf("B:(%d, %d) (%2.f, %2.f)\n", point_b->src_x, point_b->src_y, point_b->dst_x, point_b->dst_y);
			draw_line(*point_a, *point_b, img);
		}
		point_a = point_a->next;
	}
	//printf("LAST:(%d, %d) (%2.f, %2.f); ", point_a->src_x, point_a->src_y, point_a->dst_x, point_a->dst_y);
	//put_pixel_img(img, point_a->dst_x, point_a->dst_y, COLOR);
}

