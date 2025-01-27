/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:27:48 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/20 14:57:54 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_strtol(char *str, char **endptr)
{
	int		sign;
	long	result;
	int		digit;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	digit = 0;
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - 48;
		result = result * 10 + digit;
		str++;
	}
	if (endptr != NULL)
		*endptr = (char *)str;
	return (sign * result);
}
