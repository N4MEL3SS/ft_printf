#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h> //TODO: Удалить
# include <unistd.h>

# define MEM_SIZE 8
# define DEC 10
# define HEX 16

typedef struct s_form
{
	short		minus;
	short		plus;
	short		zero;
	short		space;
	short		sharp;
	short		dot;
	short		null_str;
	int			width;
	int			precision;
}				t_form;

int			ft_isdigit(int c);
int			ft_isflag(int flag);

int			ft_strlen(const char *str);
void		ft_memset(int c, int n);
void		ft_putnchar(char *str, size_t i);

void		ft_print_percent(t_form *f_flag, int *size);
void		ft_print_char(char c, t_form *f_flag, int *size);
void		ft_print_str(char *str, t_form *f_flag, int *size);
void		ft_print_int(int n, t_form *f_flag, int *size);
void		ft_print_uint(unsigned int n, t_form *f_flag, int *size);
void		ft_print_hex(unsigned int n, int x, t_form *f_flag, int *size);
void		ft_print_ptr(size_t n, t_form *f_flag, int *size);

int			ft_printf(const char *f_str, ...);
const char	*ft_pars(const char *f_str, va_list ap, t_form *f_flag);

#endif //FT_PRINTF_H
