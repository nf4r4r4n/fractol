/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:56:30 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/13 16:30:55 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef W
#  define W 800
# endif
# ifndef H
#  define H 600
# endif

typedef struct s_cpx
{
	double	x;
	double	y;
}	t_cpx;

typedef struct s_fract
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
	char	*name;
}	t_fract;

/** src/ft_errors.c */
void	ft_exit(char *msg, int err, void (*f)(void));
void	ft_handle_args(int argc, char **argv);
/** src/ft_fractol.c */
void	ft_init_fractol(t_fract *f);
void	ft_destroy_fractol(t_fract *f);
/** sr/ft_hook.c */
int		ft_key_hook(int key, t_fract *f);
int		ft_loop_hook(t_fract *f);
int		ft_close(t_fract *f);

#endif
