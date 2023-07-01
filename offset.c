/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:17:38 by rimarque          #+#    #+#             */
/*   Updated: 2023/07/01 19:01:31 by rimarque         ###   ########.fr       */
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

int	count_num(char **array)
{
	int count;

	count = 0;
	while(array[count])
	{
		count++;
	}
	return(count);
}

int	smallest_nbr(int *numbers, int y)
{
	int	smallest;
	int i;

	smallest = numbers[0];
	i = 1;
	while (i < y)
	{
		if (smallest > numbers[i])
			smallest = numbers[i];
		i++;
	}
	return (smallest);
}

int	small_line(char	***matrix, int y)
{
	int	*line_numbers;
	int i;
	int result;

	line_numbers = ft_calloc(y, sizeof(int));
	i = 0;
	while(matrix[i])
	{
		line_numbers[i] = count_num(matrix[i]);
		if (!line_numbers[i])
			return(0);
		i++;
	}
	result = smallest_nbr(line_numbers, y);
	free(line_numbers);
	return(result);
}
