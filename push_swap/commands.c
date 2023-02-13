/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 07:47:05 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/08 11:21:57 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stack(t_data *data)
{
	if (data->a_count == 2)
		swap_a(data);
	if (data->a_count == 3)
		sort_three(data);
	if (data->a_count == 4)
		sort_four(data);
	if (data->a_count == 5)
		sort_it(data);
}

void	fill_radix_stack_a(t_data *data)
{
	int	j;
	int	count;

	data->stack_a = (int *)malloc(sizeof(int) * data->a_count);
	if (!data->stack_a)
		return ;
	j = 0;
	count = data->a_count;
	while (count > 0)
	{
		data->stack_a[j] = data->input[j];
		--count;
		j++;
	}
}

void	translate(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->a_count)
	{
		j = 0;
		while (j < data->a_count)
		{
			if (data->input[i] == data->copy[j])
			{
				data->input[i] = j;
				break ;
			}
			++j;
		}
		++i;
	}
}

void	fill_input_unsorted(t_data *data)
{
	int	j;
	int	count;

	data->input = (int *)malloc(sizeof(int) * data->a_count);
	if (!data->input)
		return ;
	j = 0;
	count = data->a_count;
	while (count > 0)
	{
		data->input[j] = ft_atoi(data->str_values[j], data);
		--count;
		j++;
	}
}

void	fill_copy_sorted(t_data *data)
{
	int	j;
	int	temp_count;

	data->copy = (int *)malloc(sizeof(int) * data->a_count);
	if (!data->copy)
		return ;
	j = 0;
	temp_count = data->a_count;
	while (temp_count > 0)
	{
		data->copy[j++] = ft_atoi(data->str_values[--temp_count], data);
	}
	insertion_sort(data);
}
