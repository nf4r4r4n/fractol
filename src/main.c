/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:59:45 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/15 16:35:27 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fract	*fract;

	fract = (t_fract *)malloc(sizeof(t_fract));
	if (!fract)
		ft_exit("Fractol malloc", 1, NULL);
	ft_handle_args(argc, argv, fract);
	ft_init_fractol(fract);
	ft_render(fract, argv[1][0]);
	ft_hook(fract);
	mlx_loop(fract->mlx);
	ft_destroy_fractol(fract);
}
