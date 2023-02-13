/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:34:45 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/08 11:32:53 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_sorted_or_not(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->a_count)
	{
		if (data->input[i] != data->copy[i])
			return (1);
		i++;
	}
	return (0);
}

int	array_sorted_or_not2(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->a_count)
	{
		if (data->stack_a[i] != data->copy[i])
			return (1);
		i++;
	}
	return (0);
}

int	minimum_pos(t_data *data)
{
	int	i;
	int	position;

	i = 1;
	position = 0;
	while (i < (data->a_count))
	{
		if (data->stack_a[i] < data->stack_a[position])
			position = i;
		i++;
	}
	return (position);
}

void	check_int_duplicates(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < (data->a_count - 1))
	{
		j = i + 1;
		while (j < data->a_count)
		{
			if (data->input[i] == data->input[j])
			{
				write (2, "Error\n", 6);
				exit_free_err(data);
			}
			j++;
		}
		i++;
	}
}

int	ft_atoi(const char *str, t_data *data)
{
	data->res = 0;
	data->sign = 1;
	data->i = 0;
	while (str[data->i] == ' ' || str[data->i] == '\t')
		data->i++;
	if (str[data->i] == '-' || str[data->i] == '+')
	{
		if (str[data->i] == '-')
			data->sign = -1;
		data->i++;
	}
	if (!(str[data->i] >= '0' && str[data->i] <= '9'))
		ft_error(data);
	while (str[data->i] >= '0' && str[data->i] <= '9')
	{
		data->res = data->res * 10 + str[data->i] - '0';
		data->i++;
	}
	if (!((str[data->i] >= '0' && str[data->i] <= '9')
			|| (str[data->i] == ' ' || str[data->i] == '\0')))
		ft_error(data);
	if ((data->res * data->sign) > 2147483647
		|| (data->res * data->sign) < -2147483648)
		ft_error(data);
	return ((int)(data->res * data->sign));
}
