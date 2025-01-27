/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:36:17 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/28 11:19:33 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		chr;

	src = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n > 0)
	{
		if (*src == chr)
			return ((void *)(src));
		n--;
		src++;
	}
	return (NULL);
}
/*
int main (void)
{
	int		chr;
	void	*result;

	char string [] = "ANTOINE";
	int = 'A';
	result = ft_memchr(string, chr, sizeof(str));
	if (result != NULL)
				printf(
	printf("l'adresse de la premiere occurence de %c dans la string : %s est
		%p \n", chr, string, ft_memchr(string, chr, 7));
	return (0);
}
*/
/*
	Man
  The  memchr()  function scans the initial n bytes of the memory area pointed
   to by s for the first instance of c.  Both c and the
       bytes of the memory area pointed to by s are interpreted as unsigned char.
  The memrchr() function is like the memchr() function,
  except that it searches backward from the end of the n bytes pointed to  by
       s instead of forward from the beginning.
   Explication : The ft_memchr() function locates
    the first occurence of c (converted (cast)
   to an unsigned char) in the string s. Returns a pointer to the byte located,
    or null if no such byte exists within n bytes.
*/
