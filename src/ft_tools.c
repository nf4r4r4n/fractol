/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:53:27 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/22 11:08:09 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pix(t_fract *f, int x, int y, int color)
{
	char	*pix;

	pix = f->addr + (y * f->ll + x * (f->bpp / 8));
	*(unsigned int *)pix = color;
}

void	ft_put_img_to_win(t_fract *f, int x, int y)
{
	mlx_put_image_to_window(f->mlx, f->win, f->img, x, y);
}

int	int_map(int n, t_irange in, t_irange out)
{
	const int	delta_in = in.max - in.min;
	const int	delta_out = out.max - out.min;

	return ((n - in.min) * delta_out / delta_in + out.min);
}

int	argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

/**
	* interpolated_color = a + (b - a) * factor
*/
int	interpolate(int a, int b, double factor)
{
	int	a2[3];
	int	b2[3];
	int	c[3];

	a2[0] = (a >> 16) & 0xff;
	a2[1] = (a >> 8) & 0xff;
	a2[2] = (a >> 0) & 0xff;
	b2[0] = (b >> 16) & 0xff;
	b2[1] = (b >> 8) & 0xff;
	b2[2] = (b >> 0) & 0xff;
	c[0] = (int)(a2[0] + (b2[0] - a2[0]) * factor);
	c[1] = (int)(a2[1] + (b2[1] - a2[1]) * factor);
	c[2] = (int)(a2[2] + (b2[2] - a2[2]) * factor);
	return (0xff << 24 | (c[0] << 16) | (c[1] << 8) | c[2]);
}
