/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:49:22 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/18 09:50:25 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_new(double x, double y)
{
	t_complex	z;

	z.x = x;
	z.y = y;
	return (z);
}

t_complex	complex_sum(t_complex z1, t_complex z2)
{
	t_complex	sum;

	sum.x = z1.x + z2.x;
	sum.y = z1.y + z2.y;
	return (sum);
}

/**
 *	z^2 = x^2 + 2ixy - y^2
 */
t_complex	complex_square(t_complex z)
{
	t_complex	square;

	square.x = z.x * z.x - z.y * z.y;
	square.y = 2 * z.x * z.y;
	return (square);
}

/**
 * k scale factor for y is minus because of y axis
 * is downstairs
 */
t_complex	complex_map(t_complex z, t_range original, t_range target)
{
	t_complex	map;
	double		k;

	k = (target.end - target.start) / (original.end - original.start);
	map.x = k * z.x - target.end;
	map.y = -(k * z.y - target.end);
	return (map);
}

t_complex	complex_z_next(t_complex z, t_complex c)
{
	t_complex	z_next;

	z_next = complex_sum(complex_square(z), c);
	return (z_next);
}
