/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:07:03 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/28 14:23:15 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structures.h"

/*TEST*/

void	test_parsing_metadata(t_data *data);

/*PARSING METADATA*/

int	check_colors(t_data *data);
int	check_texture(t_data *data);
int	check_config_data(t_data *data);
int	format_color(char *line, t_data *data);
int		parse_metadata(t_data *data, int fd);

#endif /* FUNCTIONS_H */
