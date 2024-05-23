/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:01:47 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/23 12:07:33 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_mandelbrot(t_complex c, t_fract *f)
{
	t_complex	z;
	t_complex	map_c;
	int			i;

	z = complex_new(0, 0);
	map_c = complex_map(c,
			(t_range){.start = 0, .end = WIDTH},
			(t_range){.start = -2, .end = 2});
	map_c.x /= f->zoom;
	map_c.y /= f->zoom;
	i = 0;
	while (i < ITER_MAX && z.x * z.x + z.y * z.y < 4)
	{
		z = complex_z_next(z, map_c);
		i++;
	}
	return (i);
}

void	render_mandelbrot(t_fract *f)
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
			iter = is_mandelbrot(complex_new((double)j, (double)i), f);
			if (iter == ITER_MAX)
				color = 0;
			else
				color = interpolate(0x131422, 0xff2222, (double)iter / (ITER_MAX / 2));
			ft_put_pix(f, j, i, color);
			j++;
		}
		i++;
	}
}
