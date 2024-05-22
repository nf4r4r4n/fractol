/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:21:36 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/22 10:22:40 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	skip(const char *str, int *i, int *sign)
{
	while (str[*i] && ft_strchr("\t\v\n\r\f ", str[*i]))
		*i += 1;
	if (str[*i] == '-')
		*sign *= -1;
	*i += 1;
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	int		divider;
	double	result;

	divider = 10;
	sign = 1;
	result = 0;
	i = 0;
	skip(str, &i, &sign);
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result + (str[i] - '0') / (double)divider;
		divider *= 10;
		i++;
	}
	return (result * (double)sign);
}
