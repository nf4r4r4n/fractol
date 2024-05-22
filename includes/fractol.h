/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:56:30 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/22 10:36:20 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef WIDTH
#  define WIDTH 800
# endif
# ifndef HEIGHT
#  define HEIGHT 800
# endif
# ifndef ITER_MAX
#  define ITER_MAX 42
# endif
# ifndef PSYCH_BLUE
#  define PSYCH_BLUE 0x7DF9FF
# endif
# ifndef LIGHT_BLUE
#  define LIGHT_BLUE 0x7BC9FF
# endif

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
	double	jx;
	double	jy;
}	t_fract;

typedef struct s_range
{
	double	start;
	double	end;
}	t_range;

typedef struct s_irange
{
	int	min;
	int	max;
}	t_irange;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

/** src/ft_complex.c */
t_complex	complex_new(double x, double y);
t_complex	complex_sum(t_complex z1, t_complex z2);
t_complex	complex_square(t_complex z);
t_complex	complex_map(t_complex z, t_range original, t_range target);
t_complex	complex_z_next(t_complex z, t_complex c);

/** src/ft_errors.c */
void		ft_exit(char *msg, int err, void (*f)(void));
void		ft_handle_args(int argc, char **argv, t_fract *f);

/** src/ft_fractol.c */
void		ft_init_fractol(t_fract *f);
void		ft_destroy_fractol(t_fract *f);

/** src/ft_hook.c */
int			ft_key_hook(int key, t_fract *f);
int			ft_loop_hook(t_fract *f);
int			ft_close(t_fract *f);
void		ft_hook(t_fract *f);

/** src/ft_tools.c */
void		ft_put_pix(t_fract *f, int x, int y, int color);
void		ft_put_img_to_win(t_fract *f, int x, int y);
int			int_map(int n, t_irange in, t_irange out);
int			argb(int a, int r, int g, int b);
int			interpolate(int a, int b, double factor);

/** src/ft_render.c */
void		ft_set_bg(t_fract *f, int color);
void		ft_render(t_fract *f, char set);

/** src/set/mandelbrot.c */
int			is_mandelbrot(t_complex c);
void		render_mandelbrot(t_fract *f);

/** src/set/julia.c */
int			is_julia(t_complex z, t_fract *f);
void		render_julia(t_fract *f);

/** src/ft_utils.c */
double		ft_atof(const char *str);


#endif
