/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:59:57 by anastruc          #+#    #+#             */
/*   Updated: 2024/04/26 17:44:12 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_base_is_valid(char *str)

{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == '-' || str[i] == '+'
			|| (str[i] >= 9 && str[i] <= 13)
			||str[i] == ' ')
			return (0);
		i++;
	}
	if (i < 1)
		return (0);
	else
		return (i);
}

int	ft_checkchar(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base [i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (ft_base_is_valid(base) != 0)
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * ft_base_is_valid(base) + ft_cc(str[i], base);
			i++;
		}
		return (result * sign);
	}
	return (0);
}
/*
int	main(void)
{
	char	*str;
	char	*base;

	str = "101";
	base = "abcdef123-4";
	__builtin_printf("%d\n", ft_atoi_base(str, base));
	return (0);
}
*/
