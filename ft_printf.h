/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:29:06 by matascon          #+#    #+#             */
/*   Updated: 2020/07/16 09:26:31 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef PARAMETERS_FOR_FLAGS
#  define FLAGS "-0.*# +\0"
#  define TYPES "cspdiuxX%\0"
#  define NUMBERS "1234567890\0"
# endif

# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct	s_data
{
	char		*str;
	va_list		args;
	int			space;
	char		dash;
	char		zero;
	char		*width;
	char		star_w;
	char		dot;
	char		*precision;
	char		star_p;
	char		type;
	int			alternative_reader;
	long		printed;
	int			error;
}				t_data;

int				ft_printf(const char *format, ...);
t_data			*ft_control_base(t_data *data);
t_data			*ft_free_data_strs(t_data *data);
int				ft_flag_time(char *str, t_data **data);
t_data			*ft_print_time(t_data *data);
int				ft_star_pop(t_data **data);
char			*ft_join_precision(int n_zeros, char *str);
t_data			*ft_put_space(int num_spaces, t_data *data);
t_data			*ft_put_zero(int num_spaces, t_data *data);
t_data			*ft_put_str(char *str, int length, t_data *data);
char			*ft_itoa_base(long number, char *base);
t_data			*ft_print_char(t_data *data);
t_data			*ft_print_str(t_data *data);
t_data			*ft_print_int(t_data *data);
t_data			*ft_print_unsigned(t_data *data);
t_data			*ft_print_pointer(t_data *data);
t_data			*ft_print_hex(t_data *data);
t_data			*ft_print_percent(t_data *data);

#endif
