/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:32:56 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/21 14:48:58 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (8);
	return (0);
}

/*
int main (void)
{
	int	c;


	c = 64;
	__builtin_printf("Mycreation %d \nla vrai %d \n", ft_isalnum(c),
		isalnum(c));
	c = 65;
	__builtin_printf("Mycreation %d \nla vrai %d \n", ft_isalnum(c),
		isalnum(c));
	c = 90;
	__builtin_printf("Mycreation %d \nla vrai %d \n", ft_isalnum(c),
		isalnum(c));
	c = 91;
	__builtin_printf("Mycreation %d \nla vrai %d \n", ft_isalnum(c),
		isalnum(c));
	c = 97;
	__builtin_printf("Mycreation %d \nla vrai %d \n", ft_isalnum(c),
		isalnum(c));
	c = 100;
	__builtin_printf("Mycreation %d \nla vrai %d \n", ft_isalnum(c),
		isalnum(c));
	c = 122;
	__builtin_printf("Mycreation %d \nla vrai %d \n", ft_isalnum(c),
		isalnum(c));
	c = 48;
	__builtin_printf("Mycreation %d \nla vrai %d \n", ft_isalnum(c),
		isalnum(c));
	c = 55;
	__builtin_printf("Mycreation %d \nla vrai %d \n", ft_isalnum(c),
		isalnum(c));
}
*/
