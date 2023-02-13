/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:57:23 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/08 11:34:15 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_data
{
	int			size;
	int			top;
	int			bottom;
	int			temp;
	int			count;
	int			*stack_a;
	int			*stack_b;
	int			*input;
	int			*copy;
	int			*stack_temp;
	int			pa_flag;
	int			a_count;
	int			b_count;
	int			pb_flag;
	char		*str_temp;
	char		*values;
	char		**str_values;
	long		res;
	int			sign;
	long int	i;
}			t_data;

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

int		ft_atoi(const char *str, t_data *data);
int		ft_isdigit_space(char *str);
int		array_sorted_or_not(t_data *data);
int		array_sorted_or_not2(t_data *data);
int		minimum_pos(t_data *data);
size_t	ft_strlen(const char *s);

void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_ab(t_data *data);
void	push_b(t_data *data);
void	push_a(t_data *data);
void	*ft_calloc(size_t count, size_t size);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rev_rotate_a(t_data *data);
void	rev_rotate_b(t_data *data);
void	rev_rotate_ab(t_data *data);
void	sort_small_stack(t_data *data);
void	sort_three(t_data *data);
void	sort_four(t_data *data);
void	insertion_sort(t_data *data);
void	fill_radix_stack_a(t_data *data);
void	translate(t_data *data);
void	fill_input_unsorted(t_data *data);
void	fill_copy_sorted(t_data *data);
void	check_int_duplicates(t_data *data);
void	fill_stack(t_data *data);
void	sort_large_stack(t_data *data);
void	get_arg_num(t_data *data);
void	ft_error(t_data *data);
void	exit_free_err(t_data *data);
void	exit_free_err2(t_data *data);
void	no_arg_error(void);
void	free_all(t_data *data);
void	sort_it(t_data *data);

bool	is_condition1(t_data *data);
bool	is_condition2(t_data *data);
bool	is_condition3(t_data *data);
bool	is_condition4(t_data *data);
bool	is_condition5(t_data *data);

#endif