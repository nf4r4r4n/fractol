/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:20:34 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/15 16:22:08 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_bg(t_fract *f, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
			ft_put_pix(f, j++, i, color);
		i++;
	}
}

void	ft_render(t_fract *f, char set)
{
	(void)set;
	mlx_clear_window(f->mlx, f->win);
	ft_set_bg(f, 0x24283B);
	ft_put_img_to_win(f, 0, 0);
}
