/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:59:45 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/13 16:30:42 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fract	*fract;

	ft_handle_args(argc, argv);
	fract = (t_fract *)malloc(sizeof(t_fract));
	if (!fract)
		ft_exit("Fractol malloc", 1, NULL);
	ft_init_fractol(fract);
	mlx_loop_hook(fract->mlx, &ft_loop_hook, fract);
	mlx_key_hook(fract->win, &ft_key_hook, fract);
	mlx_hook(fract->win, 17, 0L, &ft_close, fract);
	mlx_loop(fract->mlx);
	ft_destroy_fractol(fract);
}
