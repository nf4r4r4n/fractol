/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:01:49 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/22 15:23:04 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_usage(void)
{
	ft_putstr_fd("Usage:     ./fractol <set>\n", 1);
	ft_putstr_fd("          ./fractol <set> <real> <imaginary> (Julia)\n", 1);
	ft_putstr_fd("Sets:\n", 1);
	ft_putstr_fd("     -[m] for mandelbrot\n", 1);
	ft_putstr_fd("     -[j] for julia\n", 1);
}

void	ft_exit(char *msg, int err, void (*f)(void))
{
	ft_putstr_fd("\e[1;31m", 1);
	ft_putstr_fd(msg, 1);
	ft_putendl_fd("\e[0m", 1);
	if (f != NULL)
		f();
	exit(err);
}

void	ft_handle_args(int argc, char **argv, t_fract *f)
{
	if (argc < 2 || ft_strlen(argv[1]) != 1)
	{
		free(f);
		ft_exit("You may try the next command", 1, &ft_usage);
	}
	if (argv[1][0] != 'm' && argv[1][0] != 'j')
	{
		free(f);
		ft_exit("You may try the next command", 1, &ft_usage);
	}
	if (argv[1][0] == 'j')
	{
		if (argc == 4)
		{
			f->jx = ft_atof(argv[2]);
			f->jy = ft_atof(argv[3]);
		}
		else
		{
			f->jx = 0.4;
			f->jy = 0.4;
		}
	}
	f->set = argv[1][0];
}
