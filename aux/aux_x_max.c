/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_x_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:17:38 by rimarque          #+#    #+#             */
/*   Updated: 2023/07/03 22:53:42 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	count_num(char **array)
{
	int	count;

	count = 0;
	while (array[count])
	{
		count++;
	}
	return (count);
}

int	smallest_nbr(int *numbers, int y)
{
	int	smallest;
	int	i;

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
	int	i;
	int	result;

	line_numbers = ft_calloc(y, sizeof(int));
	i = 0;
	while (matrix[i])
	{
		line_numbers[i] = count_num(matrix[i]);
		if (!line_numbers[i])
			return (0);
		i++;
	}
	result = smallest_nbr(line_numbers, y);
	free (line_numbers);
	return (result);
}
