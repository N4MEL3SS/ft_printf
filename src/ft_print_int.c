#include "../includes/ft_printf.h"

char	*ft_convert_int(long n, int *num_len)
{
	int		num_rank;
	char	*num;
	char	*num_start;

	if (n < 0)
		num_rank = -1;
	else
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

void	ft_logic_print_int(t_form *f_flag, int n_len, int *size)
{
	if (n_len >= f_flag->width && n_len > f_flag->precision)
	{
		f_flag->width = 0;
		f_flag->precision = 0;
	}
	else if (f_flag->width > n_len && n_len >= f_flag->precision)
	{
		f_flag->width -= (n_len + f_flag->plus);
		f_flag->precision = 0;
	}
	else if (f_flag->width > f_flag->precision && f_flag->precision > n_len)
	{
		f_flag->width -= (f_flag->precision + f_flag->plus);
		f_flag->precision -= n_len;
	}
	else if (f_flag->precision >= f_flag->width && f_flag->precision >= n_len)
	{
		f_flag->width = 0;
		f_flag->precision -= n_len;
	}
	*size += f_flag->width + f_flag->precision + f_flag->plus + n_len;
}

void	ft_put_int(char *str, t_form *f_flag, int i, char sign)
{
	if (f_flag->zero == 1)
    {
        ft_putnchar(&sign, f_flag->plus);
        ft_memset('0', f_flag->width);
        ft_putnchar(str, i);
    }
    else if (f_flag->minus == 0)
    {
        ft_memset(' ', f_flag->width);
        ft_putnchar(&sign, f_flag->plus);
        ft_memset('0', f_flag->precision);
        ft_putnchar(str, i);
    }
    else
    {
        ft_putnchar(&sign, f_flag->plus);
        ft_memset('0', f_flag->precision);
        ft_putnchar(str, i);
        ft_memset(' ', f_flag->width);
    }
}

void	ft_print_int(int n, t_form *f_flag, int *size)
{
	int		num_len;
	char	*num;
	char	sign;

	num_len = 1;
	sign = '+';
	if (n < 0)
	{
		f_flag->plus = 1;
		sign = '-';
	}
	else if (f_flag->space && !f_flag->plus)
	{
		f_flag->plus = 1;
		sign = ' ';
	}
	num = ft_convert_int(n, &num_len);
	ft_logic_print_int(f_flag, num_len, size);
	ft_put_int(num, f_flag, num_len, sign);
	free(num);
}
