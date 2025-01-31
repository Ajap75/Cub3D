/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:07:03 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/31 11:34:54 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structures.h"

/*TEST*/

void	test_parsing_metadata(t_data *data);

/*PARSING METADATA*/
int		ft_initialize(t_data *data);

int		free_char_tab(char **texture_file);
int		ft_free_exit(char *line, char **rgb_tab, t_data *data, int i);
int		ft_is_number(char *str);

int		ft_open_file(char *filename);

int		ft_clean_data_and_exit(t_data *data);

int		check_colors(t_data *data);
int		check_texture(t_data *data);
int		check_config_data(t_data *data);
int		format_ceilling_color(char *line, t_data *data);
int		format_floor_color(char *line, t_data *data);

int		parse_metadata(t_data *data, int fd);
// set textures
int		ft_set_north_texture(char *line, t_data *data);
int		ft_set_south_texture(char *line, t_data *data);
int		ft_set_west_texture(char *line, t_data *data);
int		ft_set_east_texture(char *line, t_data *data);

#endif /* FUNCTIONS_H */
