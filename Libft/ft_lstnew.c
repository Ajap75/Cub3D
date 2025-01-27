/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:52:55 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/24 14:33:49 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elemt;

	elemt = (t_list *)malloc(sizeof(t_list));
	if (!elemt)
		return (NULL);
	elemt->content = content;
	elemt->next = NULL;
	return (elemt);
}
