/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:26:39 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/06 11:38:52 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_b(t_data *data)
{
	int	count;

	count = 0;
	data->stack_temp = (int *)malloc(sizeof(int) * (data->b_count));
	while (count < (data->b_count))
	{
		data->stack_temp[count] = data->stack_b[count];
		count++;
	}
	free(data->stack_b);
	data->stack_b = (int *)malloc(sizeof(int) * (data->b_count + 1));
	if (!data->stack_b)
		return ;
	data->top = 0;
	count = 0;
	data->stack_b[data->top++] = data->stack_a[count];
	while (data->top < (data->b_count + 1))
	{
		data->stack_b[data->top] = data->stack_temp[count];
		data->top++;
		count++;
	}
	free(data->stack_temp);
}

static void	reduce_stack_a(t_data *data)
{
	int	j;

	data->stack_temp = (int *)malloc(sizeof(int) * data->a_count);
	data->top = 0;
	while (data->top < (data->a_count))
	{
		data->stack_temp[data->top] = data->stack_a[data->top];
		data->top++;
	}
	free(data->stack_a);
	data->stack_a = (int *)malloc(sizeof(int) * (data->a_count - 1));
	if (!data->stack_a)
		return ;
	data->a_count -= 1;
	data->top -= 1;
	j = 0;
	while (j < data->a_count && data->top > 0)
	{
		data->stack_a[data->top - 1] = data->stack_temp[data->top];
		data->top--;
		j++;
	}
	free(data->stack_temp);
}

void	push_b(t_data *data)
{
	if (data->b_count == 0)
	{
		data->stack_b = (int *)malloc(sizeof(int));
		if (!data->stack_b)
			return ;
		data->stack_b[0] = data->stack_a[0];
		reduce_stack_a(data);
	}
	else
	{
		fill_b(data);
		reduce_stack_a(data);
	}
	data->b_count++;
	write(1, "pb\n", 3);
}
