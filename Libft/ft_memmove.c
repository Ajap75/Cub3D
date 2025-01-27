/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:17:16 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/28 11:22:26 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destination;
	char	*source;

	destination = (char *)dest;
	source = (char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (destination > source)
	{
		while (n-- > 0)
			destination[n] = source[n];
	}
	else
	{
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[55] = "Je suis l'original source qui sera copiee dans dest";
	char	dst[55];

	__builtin_printf("source = %s\n", src);
	ft_memmove(dst, src, 55);
	__builtin_printf("dest = %s\n", dst);
	return (0);
}
*/

/*
 * The  memmove()  function  copies  n  bytes from memory area src to memory
 area dest.  The memory areas may overlap: copying takes
		place as though the bytes in src are first copied into a temporary array
		that does not overlap src or dest,  and  the  bytes  are
		then copied from the temporary array to dest.
 Explenation : In  this fonction, we want to avoid to erase the source area
 memory by copying in the dest area memory, if the dest area memory and source
  area memory are overlaping. To do so, we use a simpleway.
  If destination > source (if d the hexadecimal adress pointed by d,
   is greater than the hexadecimal adress pointed by s, there is a risk
   of erasing the source by copying in the dest. That's why we will start
   copying source in dest through the end of the string with the last
   character at the n index i the dest area memory.

RETURN VALUE
		The memmove() function returns a pointer to dest.

*/
