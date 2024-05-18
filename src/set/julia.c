/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:38:08 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/18 10:53:52 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_julia(t_complex z)
{
	t_complex	z_next;
	t_complex	c;
	int			i;

	z_next = complex_map(z,
			(t_range){.start = 0, .end = WIDTH},
			(t_range){.start = -2, .end = 2});
	c = complex_new(-0.8, 0.156);
	i = 0;
	while (i < ITER_MAX && z_next.x * z_next.x + z_next.y * z_next.y < 4)
	{
		z_next = complex_z_next(z_next, c);
		i++;
	}
	if (i == ITER_MAX)
		return (1);
	return (0);
}

void	render_julia(t_fract *f)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (is_julia(complex_new((double)j, (double)i)))
				ft_put_pix(f, j, i, 0);
			else
				ft_put_pix(f, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}
