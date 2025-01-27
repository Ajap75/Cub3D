/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:10:54 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/22 17:05:22 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

/* Locates the first occurence of c in a string. The null character \0
is part of the string
Input: const char s, int c
Return:
ptr to located char
NULL if not in the string
Explanation of the fonction structure. What we do here is to go through
the s string while we haven't reach the null byte at the end AND while
we haven't find an occurence of c in S. Once we've left the loop, we will check
why ? Is it because we've find an occurence *s == c then we return a pointer to
the occurence (casting the pointer s to a pointer to a char *char) or is
it because we've reache the null byte without finding an occurence of c. In this
case we return a pointer to NULL. A simple IF do the job
*/
