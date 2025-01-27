/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:14:43 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/22 16:14:46 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dest;

	if (dest == NULL && size == 0)
		return (0);
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	i = len_dest;
	j = 0;
	if (!size)
		return (len_src);
	if (size <= len_dest)
		return (size + len_src);
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len_dest + len_src);
}
