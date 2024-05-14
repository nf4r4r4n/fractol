/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:01:49 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/14 10:57:42 by nfararan         ###   ########.fr       */
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
	int	is_mdl;
	int	is_jul;

	is_mdl = ft_strncmp("m", argv[1], 1) != 0;
	is_jul = ft_strncmp("j", argv[1], 1) != 0;
	if (argc != 2 || (is_mdl && is_jul))
		ft_exit("You may try the next command", 1, &ft_usage);
}
