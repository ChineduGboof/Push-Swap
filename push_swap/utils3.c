/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:37:30 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/06 12:51:20 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!(s1 && s2))
		return (0);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

static int	is_digit2(char *str, int i)
{
	bool	minus;
	bool	plus;

	minus = false;
	plus = false;
	if (str[i] == '-' && minus == false)
			minus = true;
	else if (str[i] == '-' && minus == true)
		return (1);
	else
		minus = false;
	if (str[i] == '+' && plus == false)
		plus = true;
	else if (str[i] == '+' && plus == true)
		return (1);
	else
		plus = false;
	if (str[i] == '+' && str[i + 1] == '-')
		return (1);
	else if (str[i] == '-' && str[i + 1] == '+')
		return (1);
	if (!((str[i] >= 48 && str[i] <= 57) || str[i] == 32
			|| str[i] == '-' || str[i] == '+'))
		return (1);
	return (0);
}

int	ft_isdigit_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		is_digit2(str, i);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
