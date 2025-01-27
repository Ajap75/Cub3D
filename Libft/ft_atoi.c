/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:37:07 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/28 11:47:22 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;
	int	digit;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	digit = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		digit = *nptr - 48;
		result = result * 10 + digit;
		nptr++;
	}
	return (sign * result);
}

/*
int	main(void)
{
	char	*nbr;

	nbr = "-2147483649";
	__builtin_printf("la fonction atoi donne : %d \n", atoi(nbr));
	__builtin_printf("ma fonction donne : %d \n", ft_atoi(nbr));
	return (0);
}
*/
