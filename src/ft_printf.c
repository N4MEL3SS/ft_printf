/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:00:41 by celadia           #+#    #+#             */
/*   Updated: 2021/11/16 18:00:41 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*ft_print_type(const char *f_str, va_list ap, int *size)
{
	t_form	f_flag;

	f_str = ft_pars(f_str, ap, &f_flag);
	if (*f_str == 's')
		ft_print_str(va_arg(ap, char *), &f_flag, size);
	else if (*f_str == 'i' || *f_str == 'd')
		ft_print_int(va_arg(ap, int), &f_flag, size);
	else if (*f_str == 'p')
		ft_print_ptr((size_t)va_arg(ap, void *), &f_flag, size);
	else if (*f_str == 'x' || *f_str == 'X')
		ft_print_hex(va_arg(ap, int), *f_str, &f_flag, size);
	else if (*f_str == 'u')
		ft_print_uint((unsigned int)va_arg(ap, int), &f_flag, size);
	else if (*f_str == 'c')
		ft_print_char(va_arg(ap, int), &f_flag, size);
	else if (*f_str == '%')
		ft_print_percent(&f_flag, size);
	f_str++;
	return (f_str);
}

const char	*ft_print_buff(const char *f_str, int *size)
{
	int		len;
	char	*f_str_bgn;

	len = 0;
	f_str_bgn = (char *)f_str;
	while (*f_str && *f_str != '%' && ++f_str)
		++len;
	ft_putnchar(f_str_bgn, len);
	*size += len;
	return (f_str);
}

int	ft_printf(const char *f_str, ...)
{
	va_list	ap;
	int		size;

	size = 0;
	va_start(ap, f_str);
	while (*f_str)
	{
		if (*f_str && *f_str != '%')
			f_str = ft_print_buff(f_str, &size);
		else
			f_str = ft_print_type(f_str, ap, &size);
	}
	va_end(ap);
	return (size);
}
