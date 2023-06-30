/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:17:38 by rimarque          #+#    #+#             */
/*   Updated: 2023/06/30 18:42:51 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	biggest_x(t_list stack)
{
	int	biggest;
	t_node	*element;

	biggest = stack.head->dst_x;
	element = stack.head->next;
	while (element != stack.head)
	{
		if (biggest < element->dst_x)
			biggest = element->dst_x;
		element = element->next;
	}
	return (biggest);
}

int	biggest_y(t_list stack)
{
	int	biggest;
	t_node	*element;

	biggest = stack.head->dst_y;
	element = stack.head->next;
	while (element != stack.head)
	{
		if (biggest < element->dst_y)
			biggest = element->dst_y;
		element = element->next;
	}
	return (biggest);
}

int	smallest_x(t_list stack)
{
	int	smallest;
	t_node	*element;

	smallest = stack.head->dst_x;
	element = stack.head->next;
	while (element != stack.head)
	{
		if (smallest > element->dst_x)
			smallest = element->dst_x;
		element = element->next;
	}
	return (smallest);
}

int	calc_offset_x(t_list map)
{
	int	x;

	x = smallest_x(map);
	if (x < 0)
	{
		return (x * -1);
	}
	return(0);
}

int	smallest_y(t_list stack)
{
	int	smallest;
	t_node	*element;

	smallest = stack.head->dst_y;
	element = stack.head->next;
	while (element != stack.head)
	{
		if (smallest > element->dst_y)
			smallest = element->dst_y;
		element = element->next;
	}
	return (smallest);
}

int	calc_offset_y(t_list map)
{
	int	y;;

	y = smallest_y(map);
	if (y < 0)
	{
		return (y * -1);
	}
	return(0);
}
