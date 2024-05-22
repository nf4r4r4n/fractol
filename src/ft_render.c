/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:20:34 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/22 15:16:44 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_render(t_fract *f, char set)
{
	mlx_clear_window(f->mlx, f->win);
	if (set == 'm')
		render_mandelbrot(f);
	else
		render_julia(f);
	ft_put_img_to_win(f, 0, 0);
}
