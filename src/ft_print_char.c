/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:59:57 by celadia           #+#    #+#             */
/*   Updated: 2021/11/16 17:59:57 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_char(char c, t_form *f_flag)
{
	if (f_flag->width > 1)
	{
		f_flag->width -= 1;
		if (f_flag->minus == 0)
		{
			ft_memset(' ', f_flag->width);
			ft_putnchar(&c, 1);
		}
		else
		{
			ft_putnchar(&c, 1);
			ft_memset(' ', f_flag->width);
		}
	}
	else
	{
		f_flag->width = 0;
		ft_putnchar(&c, 1);
	}
}

void	ft_print_char(char c, t_form *f_flag, int *size)
{
	ft_put_char(c, f_flag);
	*size += f_flag->width + 1;
}
