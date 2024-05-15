/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:32:22 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/15 16:07:57 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_obj(t_fract *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->addr = NULL;
	f->bpp = 0;
	f->ll = 0;
	f->endian = 0;
}

void	ft_init_fractol(t_fract *f)
{
	ft_init_obj(f);
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		free(f);
		ft_exit("Mlx init", 1, NULL);
	}
	f->win = mlx_new_window(f->mlx, W, H, "Fractol");
	if (!f->win)
	{
		free(f->mlx);
		free(f);
		ft_exit("Window init", 1, NULL);
	}
	f->img = mlx_new_image(f->mlx, W, H);
	if (!f->img)
	{
		free(f->win);
		free(f->mlx);
		free(f);
		ft_exit("Image init", 1, NULL);
	}
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->ll, &f->endian);
}

void	ft_destroy_fractol(t_fract *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_display(f->mlx);
	free(f);
}
