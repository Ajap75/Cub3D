/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:30:16 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/03 12:57:28 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"

char	*skip_empty_line(t_data *data)
{
	char	*line;
	while (1)
	{
		line = get_next_line(data->config.map_file_fd);
		data->map.map_index++;
		if (line == NULL)
			return (NULL);
		else if (line[0] == '\0' || line[0] == '\n' || line[0] == '\r')
		{
			free(line);
			continue ;
		}
		else
			break ;
	}
	printf("FIRST LINE OF MAP IS \nLINE[%d] : |%s|\n", data->map.map_index, line);
	return (line);
}

int	ft_calculate_map_height_and_width(t_data *data, char *line)
{
	int	begin_index;
	begin_index = data->map.map_index;
	while (1)
	{
		line = get_next_line(data->config.map_file_fd);
		if (line == NULL)
			break;
		else if (line[0] != '\0' || line[0] != '\n' || line[0] != '\r')
		{
			data->map.map_index++;
			if (data->map.width < (int)ft_strlen(line))
				data->map.width = ft_strlen(line);
			free(line);
			continue ;
		}
		else
			break ;
	}
	if (line != NULL)
		free(line);
	data->map.height = begin_index - data->map.map_index;
	printf("Map Height = %d \n Map Width = %d\n", data->map.height, data->map.width);
	 return (0);
}


int ft_store_map(t_data *data, char *line)
{
	ft_calculate_map_height_and_width (data, line);
	return (0);
}
int	parse_map(t_data *data)
{
	char	*line;

	line = skip_empty_line(data);
	if (line == NULL)
	{
		printf("\033[31mUseError : NO_MAP\n\033[0m\n");
		ft_clean_data_and_exit(data);
	}
	ft_store_map(data, line);
	return (0);

}
