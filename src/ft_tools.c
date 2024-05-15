/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:53:27 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/15 16:12:47 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pix(t_fract *f, int x, int y, int color)
{
	char	*pix;

	pix = f->addr + (y * f->ll + x * (f->bpp / 8));
	*(unsigned int*)pix = color;
}

void	ft_put_img_to_win(t_fract *f, int x, int y)
{
	mlx_put_image_to_window(f->mlx, f->win, f->img, x, y);
}
