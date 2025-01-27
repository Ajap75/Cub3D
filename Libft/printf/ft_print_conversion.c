/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:53:56 by anastruc          #+#    #+#             */
/*   Updated: 2023/12/05 15:06:40 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_conversion(va_list arg, const char **str)
{
	int	i;

	i = 0;
	if (**str == '%' && *(*str + 1) == 'c')
		i = ft_putchar(va_arg(arg, int));
	else if (**str == '%' && *(*str + 1) == 's')
		i = ft_putstr(va_arg(arg, char *));
	else if (**str == '%' && *(*str + 1) == 'p')
		i = ((ft_putnbr_base_p(va_arg(arg, unsigned long long),
						"0123456789abcdef")));
	else if ((**str == '%' && *(*str + 1) == 'd') || (**str == '%' && *(*str
				+ 1) == 'i'))
		i = ft_putnbr(va_arg(arg, int));
	else if (**str == '%' && *(*str + 1) == 'u')
		i = ft_putnbr_u(va_arg(arg, unsigned int));
	else if (**str == '%' && *(*str + 1) == 'x')
		i = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (**str == '%' && *(*str + 1) == 'X')
		i = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (**str == '%' && *(*str + 1) == '%')
		i = ft_putchar('%');
	*str += 2;
	return (i);
}
