/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:31:59 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/08 08:08:44 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data *data)
{
	data->top = 0;
	data->temp = data->stack_a[data->top + 1];
	data->stack_a[data->top + 1] = data->stack_a[data->top];
	data->stack_a[data->top] = data->temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_data *data)
{
	data->top = 0;
	data->temp = data->stack_b[data->top + 1];
	data->stack_b[data->top + 1] = data->stack_b[data->top];
	data->stack_b[data->top] = data->temp;
	write(1, "sb\n", 3);
}

void	swap_ab(t_data *data)
{
	data->top = 0;
	data->temp = data->stack_a[data->top + 1];
	data->stack_a[data->top + 1] = data->stack_a[data->top];
	data->stack_a[data->top] = data->temp;
	data->temp = data->stack_b[data->top + 1];
	data->stack_b[data->top + 1] = data->stack_b[data->top];
	data->stack_b[data->top] = data->temp;
	write(1, "ss\n", 3);
}

void	rev_rotate_ab(t_data *data)
{
	rev_rotate_a(data);
	rev_rotate_b(data);
	write(1, "rrr\n", 4);
}

void	fill_stack(t_data *data)
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
		data->stack_a[j] = ft_atoi(data->str_values[j], data);
		--count;
		j++;
	}
}
