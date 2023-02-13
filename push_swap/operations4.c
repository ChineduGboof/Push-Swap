/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:11:00 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/06 11:39:38 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_a(t_data *data)
{
	int	i;

	data->stack_temp = (int *)malloc(sizeof(int) * (data->a_count));
	data->top = 0;
	while (data->top < (data->a_count))
	{
		data->stack_temp[data->top] = data->stack_a[data->top];
		data->top++;
	}
	free(data->stack_a);
	data->stack_a = (int *)malloc(sizeof(int) * (data->a_count + 1));
	if (!data->stack_a)
		return ;
	data->top = 0;
	i = 0;
	data->stack_a[data->top++] = data->stack_b[0];
	while (data->top < (data->a_count + 1))
	{
		data->stack_a[data->top] = data->stack_temp[i];
		data->top++;
		i++;
	}
	free(data->stack_temp);
}

static void	reduce_stack_b(t_data *data)
{
	int	j;

	data->stack_temp = (int *)malloc(sizeof(int) * data->b_count);
	data->top = 0;
	while (data->top < (data->b_count))
	{
		data->stack_temp[data->top] = data->stack_b[data->top];
		data->top++;
	}
	free(data->stack_b);
	data->stack_b = (int *)malloc(sizeof(int) * (data->b_count - 1));
	if (!data->stack_b)
		return ;
	data->b_count--;
	data->top--;
	j = 0;
	while (j < data->b_count && data->top > 0)
	{
		data->stack_b[data->top - 1] = data->stack_temp[data->top];
		data->top--;
		j++;
	}
	free(data->stack_temp);
}

void	push_a(t_data *data)
{
	data->top = 0;
	if (data->a_count == 0)
	{
		data->stack_a = (int *)malloc(sizeof(int) * data->pa_flag);
		if (!data->stack_a)
			return ;
		data->stack_a[data->top] = data->stack_b[data->top];
		reduce_stack_b(data);
	}
	else
	{
		fill_a(data);
		reduce_stack_b(data);
	}
	data->a_count++;
	write(1, "pa\n", 3);
}

void	get_arg_num(t_data *data)
{
	data->a_count = 0;
	while (data->str_values[data->a_count])
	{
		data->a_count++;
	}
	if (data->a_count == 1)
		return ;
}
