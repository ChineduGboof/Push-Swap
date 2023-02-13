/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:00:27 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/08 10:02:04 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			res++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (res);
}

static void	init_word(char *d, char *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start + i] && s[start + i] != c)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
}

static void	init_arr(char **arr, char *s, char c)
{
	int	i;
	int	j;
	int	word_size;

	i = 0;
	j = 0;
	while (s[i])
	{
		word_size = 0;
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				i++;
				word_size++;
			}
			arr[j] = (char *) malloc(word_size + 1);
			init_word(arr[j], s, c, i - word_size);
			j++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		num_words;
	char	**arr;

	if (!(s))
		return (0);
	num_words = count_words((char *) s, c);
	arr = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!arr)
		return (0);
	init_arr(arr, (char *) s, c);
	arr[num_words] = 0;
	return (arr);
}
