/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:27:47 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/06 15:02:40 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	maximum_bits(t_data *data)
{
	int	max_num;
	int	max_bits;

	max_num = data->a_count - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
	{
		++max_bits;
	}
	return (max_bits);
}

void	sort_large_stack(t_data *data)
{
	int	size;
	int	i;
	int	j;
	int	num;

	size = data->a_count;
	i = 0;
	while (i < maximum_bits(data))
	{
		j = 0;
		while (j++ < size)
		{
			num = data->stack_a[data->top];
			if (((num >> i) & 1) == 1)
				rotate_a(data);
			else
				push_b(data);
		}
		while (data->b_count != 0)
			push_a(data);
		i++;
	}
}
