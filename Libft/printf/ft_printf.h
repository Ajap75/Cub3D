/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:39:43 by anastruc          #+#    #+#             */
/*   Updated: 2024/04/26 11:11:48 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "../libft.h"

int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_putnbr(long nbr);
int				ft_print_conversion(va_list arg, const char **str);
int				ft_printf(const char *str, ...);
int				ft_putnbr_base(unsigned long long nbr, char *base);
int				ft_putnbr_u(unsigned int nbr);
int				ft_putnbr_base_p(unsigned long long nbr, char *base);
int				ft_main(void);

#endif
