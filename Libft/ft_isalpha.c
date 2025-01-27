/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:42:34 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/28 11:14:56 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	return (0);
}

/*
int	main(void)
{
	int	c;

	c = 66;
	__builtin_printf("my creation %d\nla vrai fonction %d\n", ft_isalpha(c),
		isalpha(c));
	c = 64;
	__builtin_printf("my creation %d\nla vrai fonction %d\n", ft_isalpha(c),
		isalpha(c));
	c = 98;
	__builtin_printf("my creation %d\nla vrai fonction %d\n", ft_isalpha(c),
		isalpha(c));
}
*/
