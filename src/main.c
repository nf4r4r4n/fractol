/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:59:45 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/14 10:58:20 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fract	*fract;

	fract = (t_fract *)malloc(sizeof(t_fract));
	if (!fract)
		ft_exit("Fractol malloc", 1, NULL);
	ft_handle_args(argc, argv);
	ft_init_fractol(fract);
	mlx_loop_hook(fract->mlx, &ft_loop_hook, fract);
	mlx_key_hook(fract->win, &ft_key_hook, fract);
	mlx_hook(fract->win, 17, 0L, &ft_close, fract);
	mlx_loop(fract->mlx);
	ft_destroy_fractol(fract);
}
