/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:38:05 by antoinejour       #+#    #+#             */
/*   Updated: 2024/04/26 17:46:56 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strjoin_gnl(const char *s1, const char *s2);
size_t	ft_strlen_gnl(const char *s);
char	*get_next_line_(int fd);
char	*ft_cleanline_updatesafe(char *line);
char	*ft_get_line(char *safe, char *buf, int fd);
char	*ft_strchr_gnl(char *str, char c);
char	*ft_substr_gnl(char const *line, unsigned int start, size_t len);

#endif
