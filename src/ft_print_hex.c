/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:00:04 by celadia           #+#    #+#             */
/*   Updated: 2021/11/16 18:00:04 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Функции из данного файла (ft_print_hex.c) выполняют преобразования числа
 * в 16-значение и запись в строку. Полученная строка выводится в консоль.
 */

#include "../includes/ft_printf.h"

char	*ft_convert_hex(unsigned int n, int *num_len, int x)
{
	char			*num_start;
	char			*num;
	unsigned int	num_rank;
	unsigned int	tmp;

	num_rank = 1;
	while (n / num_rank / HEX != 0 && ++*num_len)
		num_rank *= HEX;
	num = malloc(sizeof(char) * (*num_len + 1));
	num_start = num;
	while (num_rank != 0)
	{
		tmp = n / num_rank;
		if (tmp > 9)
			*num = (char)(tmp + x - 33);
		else
			*num = (char)(tmp + 48);
		n %= num_rank;
		num_rank /= HEX;
		++num;
	}
	*num = '\0';
	return (num_start);
}

void	ft_logic_print_hex(t_form *f_flag, int n_len, int *size)
{
	if (f_flag->width > f_flag->precision && f_flag->precision > n_len)
	{
		f_flag->width -= (f_flag->precision + f_flag->sharp);
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
		f_flag->width -= (n_len + f_flag->sharp);
		f_flag->precision = 0;
	}
	*size += f_flag->width + f_flag->precision + f_flag->sharp + n_len;
}

void	ft_put_hex(char *str, t_form *f_flag, int i, char *ox)
{
	if (f_flag->zero == 1)
	{
		ft_putnchar(ox, f_flag->sharp);
		ft_memset('0', f_flag->width);
		ft_putnchar(str, i);
	}
	else if (f_flag->minus == 0)
	{
		ft_memset(' ', f_flag->width);
		ft_putnchar(ox, f_flag->sharp);
		ft_memset('0', f_flag->precision);
		ft_putnchar(str, i);
	}
	else
	{
		ft_putnchar(ox, f_flag->sharp);
		ft_memset('0', f_flag->precision);
		ft_putnchar(str, i);
		ft_memset(' ', f_flag->width);
	}
}

void	ft_print_hex(unsigned int n, int x, t_form *f_flag, int *size)
{
	char	*num;
	char	ox[2];
	int		n_len;

	n_len = 1;
	if (n > 0)
	{
		ox[0] = '0';
		ox[1] = (char) x;
	}
	else
		f_flag->sharp = 0;
	num = ft_convert_hex(n, &n_len, x);
	ft_logic_print_hex(f_flag, n_len, size);
	ft_put_hex(num, f_flag, n_len, ox);
	free(num);
}
