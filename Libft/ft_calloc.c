/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:45:27 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/22 17:11:10 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	if (size == 0)
		return (malloc(0));
	if (nmemb > (2147483647 / size))
		return (0);
	str = malloc(nmemb * size);
	if (!str)
		return (0);
	ft_bzero(str, nmemb * size);
	return (str);
}

/* Calloc is similar to malloc,
	but calloc allocate nmemb elements of sizze "size".
 If either size or the number of elements is null, clloc return null.
  ~Or a pointer to null than can be freed later~.
 Calloc, malloc a memory area. ptr = malloc(nmemb * size).
 And fullfill this area with \0 using bzero (p, nmemb * size).
  https://waytolearnx.com/2018/12/difference-entre-calloc-et-malloc-en-c.html*/
