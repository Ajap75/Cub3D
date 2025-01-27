/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:38:32 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/27 19:40:51 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
	{
		del(lst->content);
		free(lst);
	}
}
/* This function delets one element of a linked string.
It takes as parameters : a pointer to a element to delet of a linked chain. and
a pointer to function del. Function del takes as a parameter a pointer to a
random type of value*.
First it checks if the pointer lst is null, if yes it stops the operation.
Then it checks if the pointer to the function del is null. If it is not null,
the function del will be use to delete the content of the elemet lst using
lst->content as parameter of the function del.
Once the content of the element erase. the function frees the memory of the
element itself. the function del is used to delete any type of content properly.
Ex if the elements is a dynamic string , the function del will use the function
free.*/
