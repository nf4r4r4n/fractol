/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:53:27 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/15 10:30:14 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pix(t_fract *f, int x, int y, int color)
{
	char	*pix;

	if (x >= 0 && x < W && y >= 0 && y < H)
	{
		pix = f->addr + (y * f->ll + x * (f->bpp / 8));
		*(int *)pix = color;
	}
}

void	ft_put_img_to_win(t_fract *f, int x, int y)
{
	mlx_put_image_to_window(f->mlx, (void *)f->win, f->img, x, y);
}
