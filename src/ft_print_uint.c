/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:00:35 by celadia           #+#    #+#             */
/*   Updated: 2021/11/16 18:00:35 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Функции из данного файла (ft_print_uint.c) выполняют преобразования числа
 * в 10-значение и запись в строку. Полученная строка выводится в консоль.
 */

#include "../includes/ft_printf.h"

char	*ft_convert_uint(unsigned int n, int *num_len)
{
	int		num_rank;
	char	*num;
	char	*num_start;

	num_rank = 1;
	while (n / num_rank / DEC != 0 && ++*num_len)
		num_rank *= DEC;
	num = malloc(sizeof(char) * (*num_len + 1));
	num_start = num;
	while (num_rank != 0)
	{
		*num = (char)(n / num_rank + 48);
		n %= num_rank;
		num_rank /= DEC;
		++num;
	}
	*num = '\0';
	return (num_start);
}

void	ft_logic_print_uint(t_form *f_flag, int n_len, int *size)
{
	if (f_flag->width > f_flag->precision && f_flag->precision > n_len)
	{
		f_flag->width -= (f_flag->precision + f_flag->plus);
		f_flag->precision -= n_len;
	}
	else if (f_flag->precision >= f_flag->width && f_flag->precision >= n_len)
	{
		f_flag->width = 0;
		f_flag->precision -= n_len;
	}
	else if (n_len >= f_flag->width && n_len > f_flag->precision)
	{
		f_flag->width = 0;
		f_flag->precision = 0;
	}
	else if (f_flag->width > n_len && n_len >= f_flag->precision)
	{
		f_flag->width -= (n_len + f_flag->plus);
		f_flag->precision = 0;
	}
	*size += f_flag->width + f_flag->precision + n_len;
}

void	ft_put_uint(char *str, t_form *f_flag, int i)
{
	if (f_flag->zero == 1)
	{
		ft_memset('0', f_flag->width);
		ft_putnchar(str, i);
	}
	else if (f_flag->minus == 0)
	{
		ft_memset(' ', f_flag->width);
		ft_memset('0', f_flag->precision);
		ft_putnchar(str, i);
	}
	else
	{
		ft_memset('0', f_flag->precision);
		ft_putnchar(str, i);
		ft_memset(' ', f_flag->width);
	}
}

void	ft_print_uint(unsigned int n, t_form *f_flag, int *size)
{
	int		num_len;
	char	*num;

	num_len = 1;
	num = ft_convert_uint(n, &num_len);
	ft_logic_print_uint(f_flag, num_len, size);
	ft_put_uint(num, f_flag, num_len);
	free(num);
}
