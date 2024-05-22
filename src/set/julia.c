/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:38:08 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/22 11:06:52 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_julia(t_complex z, t_fract *f)
{
	t_complex	z_next;
	t_complex	c;
	int			i;

	z_next = complex_map(z,
			(t_range){.start = 0, .end = WIDTH},
			(t_range){.start = -2, .end = 2});
	c = complex_new(f->jx, f->jy);
	i = 0;
	while (i < ITER_MAX && z_next.x * z_next.x + z_next.y * z_next.y < 4)
	{
		z_next = complex_z_next(z_next, c);
		i++;
	}
	return (i);
}

void	render_julia(t_fract *f)
{
	int	i;
	int	j;
	int	color;
	int	iter;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			iter = is_julia(complex_new((double)j, (double)i), f);
			color = interpolate(0, 0xFF7F3E, (double)iter / (double)ITER_MAX);
			ft_put_pix(f, j, i, color);
			j++;
		}
		i++;
	}
}
