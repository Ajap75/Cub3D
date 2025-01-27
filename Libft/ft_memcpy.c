/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:55:17 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/22 16:09:18 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pt_d;
	const unsigned char	*pt_s;

	pt_d = (unsigned char *)dest;
	pt_s = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		pt_d[i] = pt_s[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char strsrc [] = "Exemple de chaine a copy";
	char strdest [20];

	__builtin_printf("la source %s \n", strsrc);
		ft_memcpy(strdest, strsrc, sizeof(strsrc));
		__builtin_printf("la destination %s \n", strdest);

		return (0);
}*/

/*
DEF : La fonction memcpy() copie n bytes de la zone memoire src vers la zone
memoire dest. Les zones memoires ne doivent pas se chevaucher.

If the memcpy function were to use the parameters directly without creating
new pointers,
	it might inadvertently suggest that it modifies the original source data,
	which could lead to unintended consequences and violate the const-correctness
		principle. By using separate pointers,
	the function makes it clear that it works with copies of the source
	and destination addresses,
	allowing it to maintain flexibility, const-correctness, and versatility.

In summary,
	the use of separate pointers in memcpy is a design choice that helps ensure
		const-correctness,
	flexibility, and versatility in memory copying operations.

return : la foction memcpy retourne un pointeur sur dest.
 Soit uen valeur de type "adresse d'un octet"
Valeur retournee : La fonction memcpy() renvoie un pointeur sur la zone memoire
dest. "void*" correspond a une donnee de type pointeur vers Octet,
	on peut donc declarer une variable de type "void*".
	Si une fonction est de type "void*"
	elle retournera uen valeur de type << adresse d'un octet>>
*/
