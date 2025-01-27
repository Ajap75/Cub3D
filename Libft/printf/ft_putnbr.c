/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:16:45 by anastruc          #+#    #+#             */
/*   Updated: 2023/12/07 08:57:00 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i = 1;
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nbr);
		i++;
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else if (nbr <= 9)
		ft_putchar(nbr + 48);
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
