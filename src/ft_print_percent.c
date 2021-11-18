/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:00:11 by celadia           #+#    #+#             */
/*   Updated: 2021/11/16 18:00:11 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Функции из данного файла (ft_print_percent.c) выполняют преобразования и
 * вывод символа '%' в консоль.
 */

#include "../includes/ft_printf.h"

void	ft_put_percent(t_form *f_flag)
{
	if (f_flag->width > 1)
	{
		f_flag->width -= 1;
		if (f_flag->zero == 1)
		{
			ft_memset('0', f_flag->width);
			ft_putnchar("%", 1);
		}
		else if (f_flag->minus == 1)
		{
			ft_putnchar("%", 1);
			ft_memset(' ', f_flag->width);
		}
		else
		{
			ft_memset(' ', f_flag->width);
			ft_putnchar("%", 1);
		}
	}
	else
		ft_putnchar("%", 1);
}

void	ft_print_percent(t_form *f_flag, int *size)
{
	ft_put_percent(f_flag);
	*size += f_flag->width + 1;
}
