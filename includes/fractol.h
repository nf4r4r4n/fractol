/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:56:30 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/14 11:07:04 by nfararan         ###   ########.fr       */
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
# ifndef MAX
#  define MAX 200
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
/** src/ft_hook.c */
int		ft_key_hook(int key, t_fract *f);
int		ft_loop_hook(t_fract *f);
int		ft_close(t_fract *f);
/** src/ft_tools.c */
void	ft_put_pix(t_fract *f, int x, int y, int color);
void	ft_put_img_to_win(t_fract *f, int x, int y);
/** src/ft_render.c */
void	ft_set_bg(t_fract *f, int color);
/** src/set/mandelbrot.c */
void	ft_calc_mandel(t_fract *f, int x, int y);

#endif
