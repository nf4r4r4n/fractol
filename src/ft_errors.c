/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:01:49 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/13 14:22:35 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_usage(void)
{
	ft_putstr_fd("Usage:     ./fractol <set>\n", 1);
	ft_putstr_fd("Sets:\n", 1);
	ft_putstr_fd("     -[m]andelbrot\n", 1);
	ft_putstr_fd("     -[j]ulia\n", 1);
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

void	ft_handle_args(int argc, char **argv)
{
	if (argc != 2)
		ft_exit("You may try the next command", 1, &ft_usage);
	if (ft_strncmp("m", argv[1], 1) == 0)
		ft_putstr_fd("Mandelbrot Set\n", 1);
	else if (ft_strncmp("j", argv[1], 1) == 0)
		ft_putstr_fd("Julia Set\n", 1);
	else
		ft_exit("You may try the next command", 1, &ft_usage);
}
