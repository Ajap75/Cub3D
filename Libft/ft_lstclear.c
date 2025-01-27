/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:29:46 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/25 17:32:52 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

/* This function takes as parameters a pointer to a pointer of structure
and a a pointer to a function which take as a parameter of type void. This
function does not return anything.
A pointer to a structure is declared. It will be used later to store the value
of the next element in the list temporary.
First it checks if : The pointer is null, then if the pointed element exists,
and if the function exists.
It starts a loop which iterate while the pointer to the list or the list isn't
NULL.
1)The value of the member next in the strucutre pointed to by lst
2)The value of the member content in the strucutre pointed to by lst is deleted
3)Free the memory of the element pointed to by lst.
4) Update the pointer to the list to the next element

At the end of the loop the pointer to list is assigned to NULL. It means the
list is now empty.

 */
