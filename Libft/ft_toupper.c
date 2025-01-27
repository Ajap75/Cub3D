/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:57:17 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/22 16:13:17 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

/*
int	main(void)
{
	int	c;

	c = 97;
	__builtin_printf("___toupper___\n Mycreation et la vraie fonction %d,
		%d et la valeur ascii %c", ft_toupper(c), toupper(c), c);
	c = 122;
	__builtin_printf("___toupper___\n Mycreation et la vraie fonction %d,
		%d et la valeur ascii %c", ft_toupper(c), toupper(c), c);
	c = 100;
	__builtin_printf("___toupper___\n Mycreation et la vraie fonction %d,
		%d et la valeur ascii %c", ft_toupper(c), toupper(c), c);
	c = 48;
	__builtin_printf("___toupper___\n Mycreation et la vraie fonction %d,
		%d et la valeur ascii %c", ft_toupper(c), toupper(c), c);
	c = 56;
	__builtin_printf("___toupper___\n Mycreation et la vraie fonction %d,
		%d et la valeur ascii %c", ft_toupper(c), toupper(c), c);
	c = 78;
	__builtin_printf("___toupper___\n Mycreation et la vraie fonction %d,
		%d et la valeur ascii %c", ft_toupper(c), toupper(c), c);
	c = 101;
	__builtin_printf("___toupper___\n Mycreation et la vraie fonction %d,
		%d et la valeur ascii %c", ft_toupper(c), toupper(c), c);
	c = 104;
	__builtin_printf("___toupper___\n Mycreation et la vraie fonction %d,
		%d et la valeur ascii %c", ft_toupper(c), toupper(c), c);
}
*/
