/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 08:46:35 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/08 11:00:10 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_free_err(t_data *data)
{
	int	j;

	j = 0;
	free(data->input);
	free(data->copy);
	while (data->str_values[j])
	{
		free(data->str_values[j]);
		j++;
	}
	free(data->str_values);
	free(data);
	exit (0);
}

void	exit_free_err2(t_data *data)
{
	free(data->input);
	free(data->copy);
	free(data);
	exit (0);
}

void	ft_error(t_data *data)
{
	int	j;

	j = 0;
	write (2, "Error\n", 6);
	while (data->str_values[j])
	{
		free(data->str_values[j]);
		j++;
	}
	free(data->str_values);
	free(data->input);
	free(data->copy);
	free(data->stack_a);
	free(data);
	exit (0);
	return ;
}

void	no_arg_error(void)
{
	write (2, "Error\n", 6);
	exit (0);
}

void	free_all(t_data *data)
{
	int	j;

	j = 0;
	while (data->str_values[j])
	{
		free(data->str_values[j++]);
	}
	free(data->str_values);
	free(data->stack_a);
	free(data->stack_b);
	free(data->copy);
	free(data->input);
	free(data);
}
