/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:00:43 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/28 11:25:16 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		*ptr = (unsigned char)c;
		i++;
		ptr++;
	}
	return (s);
}

/*
int	main(void)
{
	char	str[43] = "Est ce que cette chaine va etre modifiee";

	__builtin_printf("l'original %s\n", str);
	__builtin_printf("l'adresse de la zone memoire modifie %p\n", ft_memset(str,
			100, 5));
	__builtin_printf("la de la modif %s\n", str);
	return (0);
}


DEF : La fonction memset() remplit les n premiers octets
de la zone memoire
pointee par s avec l'octet c.

Valeur retournee : La fonction memset() renvoie un pointeur sur la zone
memoire s. "void*" correspond a une donnee de type pointeur vers Octet,
	on peut donc declarer une variable de type "void*". Si une fonction est
	de type "void*" elle retournera uen valeur de type
	<< adresse d'un octet>>
*/
