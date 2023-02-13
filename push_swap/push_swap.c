/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:45:37 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/08 11:27:26 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_data *data)
{
	translate(data);
	fill_radix_stack_a(data);
	sort_large_stack(data);
}

void	error_checks(t_data *data)
{
	if (ft_isdigit_space(data->values) == 1)
	{
		write (2, "Error\n", 6);
		exit_free_err2(data);
	}
}

void	commence(t_data *data)
{
	get_arg_num(data);
	fill_input_unsorted(data);
	fill_copy_sorted(data);
	check_int_duplicates(data);
	if (array_sorted_or_not(data) == 0)
		exit_free_err(data);
	if (data->a_count > 5)
		radix_sort(data);
	else
	{
		fill_stack(data);
		sort_small_stack(data);
	}
}

void	extract_num(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	data->values = ft_strdup("");
	while (i < argc)
	{
		data->str_temp = data->values;
		data->values = ft_strjoin(data->str_temp, argv[i]);
		free (data->str_temp);
		data->str_temp = NULL;
		data->str_temp = data->values;
		data->values = ft_strjoin(data->str_temp, " ");
		free (data->str_temp);
		data->str_temp = NULL;
		i++;
	}
	error_checks(data);
	data->str_values = ft_split(data->values, ' ');
	free (data->values);
	commence(data);
}

int	main(int argc, char **argv)
{
	int		j;
	t_data	*data;

	if (argc < 2)
		return (0);
	j = 0;
	while (j < argc)
	{
		if (argv[j][0] == 0)
			no_arg_error();
		j++;
	}
	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (1);
	extract_num(argc, argv, data);
	free_all(data);
}
