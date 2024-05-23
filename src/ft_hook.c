/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:43:51 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/23 10:51:59 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_hook(int keysym, t_fract *f)
{
	if (keysym == K_ESCAPE)
	{
		mlx_destroy_window(f->mlx, f->win);
		f->win = NULL;
	}
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, t_fract	*f)
{
	(void)x;
	(void)y;
	if (button == M_WHEEL_FOR)
		f->zoom -= 20.0;
	else if (button == M_WHEEL_BACK)
		f->zoom += 20.0;
	else if (button == M_LEFT)
		f->zoom = 1.0;
	ft_render(f, f->set);
	return (0);
}

int	ft_loop_hook(t_fract *f)
{
	(void)f;
	return (0);
}

int	ft_close(t_fract *f)
{
	mlx_destroy_window(f->mlx, f->win);
	f->win = NULL;
	return (0);
}

void	ft_hook(t_fract *f)
{
	mlx_loop_hook(f->mlx, &ft_loop_hook, f);
	mlx_key_hook(f->win, &ft_key_hook, f);
	mlx_mouse_hook(f->win, &ft_mouse_hook, f);
	mlx_hook(f->win, 17, 0L, &ft_close, f);
}
