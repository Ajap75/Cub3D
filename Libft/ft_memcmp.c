/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:44:54 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/28 11:22:54 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n)
	{
		while (i < (n - 1) && (str1[i] == str2[i]))
			i++;
		return (str1[i] - str2[i]);
	}
	else
		return (0);
}
/*
int main (void)
{
	char str1 [] = "Hello World";
	char str2 [] = "Hello World";
	__builtin_printf("resultat de la vrai fonction :%d\n", memcmp (str1, str2,
			sizeof str1));
	__builtin_printf("resultat de ft_memcmp fonction :%d\n", memcmp (str1, str2,
			sizeof str1));
	return (0);
}
*/
