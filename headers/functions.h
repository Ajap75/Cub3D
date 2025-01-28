/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:07:03 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/28 12:19:22 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structures.h"

/*TEST*/

void	test_parsing_metadata(t_data *data);

/*PARSING METADATA*/

void	check_colors(t_data *data);
void	check_texture(t_data *data);
void	check_config_data(t_data *data);
void	format_color(char *line, t_data *data);
int		parse_metadata(t_data *data, int fd);

#endif /* FUNCTIONS_H */
