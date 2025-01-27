/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:33:42 by anastruc          #+#    #+#             */
/*   Updated: 2023/12/07 08:57:24 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_necessaryconversion(char c)
{
	int		i;
	char	*base;

	base = "cspdiuxX%";
	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	arg;

	len = 0;
	va_start(arg, str);
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '%' && ft_necessaryconversion(*(str + 1)))
		{
			len += ft_print_conversion(arg, &str);
		}
		else
		{
			len += ft_putchar(*str);
			str++;
		}
	}
	va_end(arg);
	return (len);
}
