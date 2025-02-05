/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:35:49 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/05 17:49:08 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"

int	ft_store_metadata(t_data *data)
{
	char	*line;

	data->config.map_file_fd = ft_open_file(data->config.map_filename);
	while (1)
	{
		line = get_next_line(data->config.map_file_fd);
		data->map.begin_map_index++;
		printf("Line[%d] = |%s|\n", data->map.begin_map_index, line);
		if (line == NULL || data->config.metadata_count == 6)
		{
			if (line != NULL)
				return (free(line), 1);
			return (1);
		}
		ft_set_texture(data, line);
		free(line);
		continue ;
	}
	return (0);
}
