/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:19:13 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/28 11:43:30 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	int		i;
	int		length;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	newstring = malloc(sizeof(char) * (length + 1));
	if (!newstring)
		return (NULL);
	i = 0;
	while (*s1)
		newstring[i++] = *s1++;
	while (*s2)
		newstring[i++] = *s2++;
	newstring[i] = '\0';
	return (newstring);
}
