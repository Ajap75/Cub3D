/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:16:45 by anastruc          #+#    #+#             */
/*   Updated: 2023/12/07 08:48:07 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i = ft_putchar(nbr + 48);
	else if (nbr > 9)
	{
		i += ft_putnbr_u(nbr / 10);
		i += ft_putnbr_u(nbr % 10);
	}
	else if (nbr <= 9)
		i += ft_putchar(nbr + 48);
	return (i);
}
