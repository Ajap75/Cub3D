/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:57:21 by anastruc          #+#    #+#             */
/*   Updated: 2023/12/07 08:42:03 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr >= ft_strlen(base))
	{
		i += ft_putnbr_base(nbr / ft_strlen(base), base);
		i += ft_putnbr_base(nbr % ft_strlen(base), base);
	}
	else if (nbr < ft_strlen(base))
		i += ft_putchar(nbr[base]);
	return (i);
}
