/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:01:07 by anastruc          #+#    #+#             */
/*   Updated: 2023/12/05 15:35:26 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_p(unsigned long long nbr, char *base)
{
	int	i;

	i = 0;
	if (!nbr)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	i += ft_putnbr_base(nbr, base);
	return (i);
}
