#include "../includes/ft_printf.h"

void	ft_putnchar(char *str, size_t i)
{
	if (i > 0)
		write(1, str, i);
}
