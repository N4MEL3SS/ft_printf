/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:59:47 by celadia           #+#    #+#             */
/*   Updated: 2021/11/18 13:41:02 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *
 * Функция ft_memset выделяет в куче память размером n байт и заполняет
 * её символом 'c', после чего полученную строку выводит на экран.
 * По завершению этих действий память освобождается.
 *
 * Функция ft_memset_fat вызывается только в том случае если n > 16.
 * Её отличие от ft_memset лишь в том, что она заполняет память
 * размером 8 байт за один проход.
 *
 */

#include "../includes/ft_printf.h"

int	ft_memset_fat(char *dst, int n)
{
	unsigned long	*src;
	unsigned long	*dest;

	src = (unsigned long *)dst;
	dest = src + 1;
	while (n >= MEM_SIZE)
	{
		*(dest++) = *src;
		n -= MEM_SIZE;
	}
	return (n);
}

void	ft_memset(int c, int n)
{
	char	*dst;
	int		i;

	if (n > 0)
	{
		i = 0;
		dst = malloc(sizeof(char) * n);
		if (n >= MEM_SIZE * 2)
		{
			while (i < MEM_SIZE)
				dst[i++] = (char) c;
			i = n - ft_memset_fat(dst, n - MEM_SIZE);
		}
		while (i < n)
			dst[i++] = (char) c;
		ft_putnchar(dst, n);
		free(dst);
	}
}
