/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 07:24:16 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/06 14:12:22 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_condition1(t_data *data)
{
	return (data->stack_a[data->bottom] > data->stack_a[data->top]
		&& data->stack_a[data->top] > data->stack_a[data->top + 1]
		&& data->stack_a[data->bottom] > data->stack_a[data->top + 1]);
}

bool	is_condition2(t_data *data)
{
	return (data->stack_a[data->bottom] < data->stack_a[data->top]
		&& data->stack_a[data->top] > data->stack_a[data->top + 1]
		&& data->stack_a[data->bottom] < data->stack_a[data->top + 1]);
}

bool	is_condition3(t_data *data)
{
	return (data->stack_a[data->bottom] < data->stack_a[data->top]
		&& data->stack_a[data->top] > data->stack_a[data->top + 1]
		&& data->stack_a[data->bottom] > data->stack_a[data->top + 1]);
}

bool	is_condition4(t_data *data)
{
	return (data->stack_a[data->bottom] > data->stack_a[data->top]
		&& data->stack_a[data->top] < data->stack_a[data->top + 1]
		&& data->stack_a[data->bottom] < data->stack_a[data->top + 1]);
}

bool	is_condition5(t_data *data)
{
	return (data->stack_a[data->bottom] < data->stack_a[data->top]
		&& data->stack_a[data->top] < data->stack_a[data->top + 1]
		&& data->stack_a[data->bottom] < data->stack_a[data->top + 1]);
}
