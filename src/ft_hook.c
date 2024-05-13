/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:43:51 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/13 16:29:54 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_hook(int key, t_fract *f)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(f->mlx, f->win);
		f->win = NULL;
	}
	return (0);
}

int	ft_loop_hook(t_fract *f)
{
	int	i;
	int	j;

	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
			ft_put_pix(f, j++, i, 0);
		i++;
	}
	ft_put_img_to_win(f, 0, 0);
	return (0);
}

int	ft_close(t_fract *f)
{
	mlx_destroy_window(f->mlx, f->win);
	f->win = NULL;
	return (0);
}
