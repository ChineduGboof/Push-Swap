/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:10:06 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/08 11:34:54 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	data->bottom = data->a_count - 1;
	data->top = 0;
	if (is_condition1(data) == true)
		swap_a(data);
	else if (is_condition2(data) == true)
	{
		swap_a(data);
		rev_rotate_a(data);
	}
	else if (is_condition3(data) == true)
		rotate_a(data);
	else if (is_condition4(data) == true)
	{
		swap_a(data);
		rotate_a(data);
	}
	else if (is_condition5(data) == true)
		rev_rotate_a(data);
}

void	sort_four(t_data *data)
{
	int	min_pos;

	min_pos = minimum_pos(data);
	if (array_sorted_or_not2(data) == 0)
		return ;
	if (min_pos == 1)
		rotate_a(data);
	else if (min_pos == 2)
	{
		rotate_a(data);
		rotate_a(data);
	}
	else if (min_pos == 3)
	{
		rev_rotate_a(data);
	}
	if (array_sorted_or_not2(data) == 0)
		return ;
	push_b(data);
	sort_three(data);
	push_a(data);
}

void	sort_it(t_data *data)
{
	int	min_pos;

	min_pos = minimum_pos(data);
	if (array_sorted_or_not2(data) == 0)
		return ;
	if (min_pos == 1)
		rotate_a(data);
	else if (min_pos == 2)
	{
		rotate_a(data);
		rotate_a(data);
	}
	else if (min_pos == 3)
	{
		rev_rotate_a(data);
		rev_rotate_a(data);
	}
	else if (min_pos == 4)
		rev_rotate_a(data);
	if (array_sorted_or_not2(data) == 0)
		return ;
	push_b(data);
	sort_four(data);
	push_a(data);
}

void	insertion_sort(t_data *data)
{
	int	temp;
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < data->a_count)
	{
		temp = data->copy[i];
		j = i - 1;
		while (j >= 0 && data->copy[j] > temp)
		{
			data->copy[j + 1] = data->copy[j];
			j--;
		}
		data->copy[j + 1] = temp;
		i++;
	}
}
