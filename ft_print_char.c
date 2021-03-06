/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 08:13:45 by matascon          #+#    #+#             */
/*   Updated: 2020/07/21 09:09:16 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*aux_parse_char(t_data *data, char var, int width)
{
	if (data->dash)
	{
		ft_putchar_fd(var, 1);
		(data->printed)++;
		data = ft_put_space(width - 1, data);
	}
	else
	{
		if (data->zero)
			data = ft_put_zero(width - 1, data);
		else
			data = ft_put_space(width - 1, data);
		ft_putchar_fd(var, 1);
		(data->printed)++;
	}
	return (data);
}

static t_data	*parse_char(t_data *data, int width)
{
	char	var;

	var = (char)va_arg(data->args, int);
	if ((unsigned)(data->printed + width) <= (unsigned)INT_MAX)
		data = aux_parse_char(data, var, width);
	else
		data->error = 1;
	return (data);
}

t_data			*ft_print_char(t_data *data)
{
	int		width;
	int		precision;

	width = 0;
	precision = 0;
	if (data->star_w)
		width = ft_star_pop(&data);
	else if (data->width)
		width = ft_atoi(data->width);
	if (data->star_p)
		precision = ft_star_pop(&data);
	else if (data->precision)
		precision = ft_atoi(data->precision);
	if (width < 0)
	{
		data->dash = '-';
		width *= -1;
	}
	data = parse_char(data, width);
	return (data);
}
