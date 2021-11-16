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
