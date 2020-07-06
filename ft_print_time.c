/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 08:14:08 by matascon          #+#    #+#             */
/*   Updated: 2020/07/06 09:24:14 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*ft_print_time(t_data *data)
{
	if (data->type == 'c')
		data = ft_print_char(data);
	else if (data->type == 's')
		data = ft_print_str(data);
	else if (data->type == 'd' || data->type == 'i')
		data = ft_print_int(data);
	return (data);
}
