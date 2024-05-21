/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:20:34 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/21 16:12:13 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_render(t_fract *f, char set)
{
	(void)set;
	mlx_clear_window(f->mlx, f->win);
	render_julia(f);
	// render_mandelbrot(f);
	ft_put_img_to_win(f, 0, 0);
}
