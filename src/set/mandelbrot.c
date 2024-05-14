/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:01:47 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/14 11:11:10 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calc_mandel(t_fract *f, int x, int y)
{
	t_cpx	z;
	t_cpx	c;
	int		i;

	z = (t_cpx){.x = 0.0, .y = 0.0};
	c = (t_cpx){.x = (double)x, .y = (double)y};
	i = 0;
	while (i < MAX && z.x * z.x + z.y * z.y < 4)
	{
		z.x = ;
		z.y = ;
		i++;
	}
	if (i == MAX)
		ft_put_pix(f, x, y, 0);
	else
		ft_put_pix(f, x, y, 0xFF0000);
}
