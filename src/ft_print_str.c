/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:00:25 by celadia           #+#    #+#             */
/*   Updated: 2021/11/16 18:00:25 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Функции из данного файла (ft_print_str.c) выполняют преобразования и вывод
 * строки str в консоль.
 */

#include "../includes/ft_printf.h"

char	*ft_null_str(void)
{
	char	*null_str;

	null_str = malloc(sizeof(char) * 7);
	null_str[0] = '(';
	null_str[1] = 'n';
	null_str[2] = 'u';
	null_str[3] = 'l';
	null_str[4] = 'l';
	null_str[5] = ')';
	null_str[6] = '\0';
	return (null_str);
}

void	ft_logic_print_str(t_form *f_flag, int *str_len)
{
	if (f_flag->dot != 0 && f_flag->precision < *str_len)
		*str_len = f_flag->precision;
	if (f_flag->width > *str_len)
		f_flag->width -= *str_len;
	else
		f_flag->width = 0;
}

void	ft_put_str(char *str, t_form *f_flag, const int *str_len)
{
	if (f_flag->minus == 0)
	{
		ft_memset(' ', f_flag->width);
		ft_putnchar(str, *str_len);
	}
	else
	{
		ft_putnchar(str, *str_len);
		ft_memset(' ', f_flag->width);
	}
}

void	ft_print_str(char *str, t_form *f_flag, int *size)
{
	int	str_len;

	if (!str && ++f_flag->null_str)
	{
		str = ft_null_str();
		if (f_flag->precision == 0 && f_flag->width == 0)
			f_flag->dot = 0;
	}
	str_len = ft_strlen(str);
	ft_logic_print_str(f_flag, &str_len);
	ft_put_str(str, f_flag, &str_len);
	*size += f_flag->width + str_len;
	if (f_flag->null_str == 1)
		free(str);
}
