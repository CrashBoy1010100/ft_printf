/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:29:06 by matascon          #+#    #+#             */
/*   Updated: 2020/07/01 13:20:34 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	char	dash;
	char	zero;
	char	*left;
	char	dot;
	char	*right;
	char	star;
	char	type;
	int		chr_read;
}				t_flags;

int		ft_print(char *str, va_list args);
void	ft_flags_time(char *str, t_flags *flags);

#endif
