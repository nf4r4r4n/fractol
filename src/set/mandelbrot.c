/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:01:47 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/18 10:34:02 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_mandelbrot(t_complex c)
{
	t_complex	z;
	t_complex	map_c;
	int			i;

	z = complex_new(0, 0);
	map_c = complex_map(c,
			(t_range){.start = 0, .end = WIDTH},
			(t_range){.start = -2, .end = 2});
	i = 0;
	while (i < ITER_MAX && z.x * z.x + z.y * z.y < 4)
	{
		z = complex_z_next(z, map_c);
		i++;
	}
	if (i == ITER_MAX)
		return (1);
	return (0);
}

void	render_mandelbrot(t_fract *f)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (is_mandelbrot(complex_new((double)j, (double)i)))
				ft_put_pix(f, j, i, 0);
			else
				ft_put_pix(f, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}
