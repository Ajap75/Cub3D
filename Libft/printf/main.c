/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:56:31 by anastruc          #+#    #+#             */
/*   Updated: 2024/04/26 17:45:56 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "ft_printf.h"
int	main (void)
{
	char	*a;
	int		*b;
	char	*c;
	int	j;
	int	i;
	int k;
	int	l;
	int	m;
	c = "coucou";
	b = &k;
	a = NULL;

	printf ("Test des cas particuliers\n-----------------------\n");
	printf ("\nTest pour une chaine vide \n");
	i = ft_printf(NULL);
	j = printf(NULL);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\nTest pour une chaine vide via pointeur sur chaine vide\n");
	i = ft_printf("%s\n", a);
	j = printf("%s\n", a);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\nTest pour une chaine vide via pointeur sur chaine vide viacast\n");
	i = ft_printf("%s\n", (char*)0);
	j = printf("%s\n",(char*)0);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\nTest pour %%p\n---------------------------");
	printf ("\nTest pour un pointeur NULL\n");
	i = ft_printf("%p\n", (void*)0);
	j = printf("%p\n",(void*)0);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\nTest pour un pointeur sur int\n");
	i = ft_printf("%p\n", b);
	j = printf("%p\n", b);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\nTest pour un pointeur sur char\n");
	i = ft_printf("%p\n", c);
	j = printf("%p\n", c);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\nTest pour %%d\n---------------------------");
	printf ("\nTest pour un intmax/\n");

	l = 2147483647;
	i = ft_printf("%d\n", l);
	j = printf("%d\n", l);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\nTest pour un intmin/\n");
	m = -2147483648;
	i = ft_printf("%d\n", m);
	j = printf("%d\n", m);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\nTest pour %%x\n---------------------------\n");

	l = 2147483647;
	i = ft_printf("%x\n", l);
	j = printf("%x\n", l);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\nTest pour un intmin/\n");
	m = -2147483648;
	i = ft_printf("%x\n", m);
	j = printf("%x\n", m);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\n test pout un int negatif /\n");
	m = -10;
	i = ft_printf("%x\n", m);
	j = printf("%x\n", m);
	printf("%d\n", i);
	printf("%d\n", j);


	printf ("\n test pout un int negatif /\n");
	m = 0;
	i = ft_printf("%x\n", m);
	j = printf("%x\n", m);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\nTest pour %%X\n---------------------------\n");

	l = 2147483647;
	i = ft_printf("%X\n", l);
	j = printf("%X\n", l);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\nTest pour un intmin/\n");
	m = -2147483648;
	i = ft_printf("%X\n", m);
	j = printf("%X\n", m);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\n test pout un int negatif /\n");
	m = -10;
	i = ft_printf("%X\n", m);
	j = printf("%X\n", m);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\n test pout un int negatif /\n");
	m = 0;
	i = ft_printf("%X\n", m);
	j = printf("%X\n", m);
	printf("%d\n", i);
	printf("%d\n", j);


	printf ("\nTest pour %%u\n---------------------------\n");

	l = 2147483647;
	i = ft_printf("%u\n", l);
	j = printf("%u\n", l);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\nTest pour un intmin/\n");
	m = -2147483648;
	i = ft_printf("%u\n", m);
	j = printf("%u\n", m);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\n test pout un int negatif /\n");
	m = -10;
	i = ft_printf("%u\n", m);
	j = printf("%u\n", m);
	printf("%d\n", i);
	printf("%d\n", j);

	printf ("\n test pout un int negatif /\n");
	m = 0;
	i = ft_printf("%u\n", m);
	j = printf("%u\n", m);
	printf("%d\n", i);
	printf("%d\n", j);

return (0);
}
*/