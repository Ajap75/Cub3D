/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_metadata.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:54:36 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/03 12:40:25 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"

int	parse_metadata(t_data *data)
{
	ft_check_for_doublon(data);
	ft_store_metadata(data);
	check_config_data(data);
	parse_map(data);
	return (0);
}

int	ft_store_metadata(t_data *data)
{
	char	*line;
	data->config.map_file_fd = ft_open_file(data->config.map_filename);
	while (1)
	{

		line = get_next_line(data->config.map_file_fd);
		data->map.map_index++;

		printf("Line[%d] = |%s|\n", data->map.map_index, line);
		if (line == NULL || data->config.metadata_count == 6)
		{
			if (line != NULL)
				return (free(line), 1);
			return (1);
		}
		else if (ft_strncmp("NO ", line, 3) == 0)
			ft_set_north_texture(line, data);
		else if (ft_strncmp("SO ", line, 3) == 0)
			ft_set_south_texture(line, data);
		else if (ft_strncmp("WE ", line, 3) == 0)
			ft_set_west_texture(line, data);
		else if (ft_strncmp("EA ", line, 3) == 0)
			ft_set_east_texture(line, data);
		else if (ft_strncmp("F ", line, 2) == 0)
			format_floor_color(line, data);
		else if (ft_strncmp("C ", line, 2) == 0)
			format_ceilling_color(line, data);
		else
		{
			free(line);
			continue ;
		}
	}
	return (0);
}

int	ft_check_for_doublon(t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(data->config.map_file_fd);
		if (line == NULL)
			return (1);
		ft_check_north_doublon(line, data);
		ft_check_south_doublon(line, data);
		ft_check_west_doublon(line, data);
		ft_check_east_doublon(line, data);
		ft_check_floor_doublon(line, data);
		ft_check_ceilling_doublon(line, data);
		printf("line = |%s|\n", line);
		free(line);

	}
	return (0);
}



int	format_ceilling_color(char *line, t_data *data)
{
	int		i;
	char	**rgb_tab;

	i = 0;
	rgb_tab = ft_split(line, 44);
	ft_print_tab(rgb_tab);
	ft_trim_tab(rgb_tab);
	ft_print_tab(rgb_tab);
	while (rgb_tab[i])
		i++;
	if (i != 3)
		ft_free_exit(line, rgb_tab, data, 1);
	i = 0;
	while (i < 3)
	{
		if (!ft_is_number(rgb_tab[i]))
			ft_free_exit(line, rgb_tab, data, 2);
		data->config.ceiling_color[i] = ft_atoi(rgb_tab[i]);
		i++;
	}
	data->config.metadata_count++;
	free(line);
	free_char_tab(rgb_tab);
	return (0);
}

int	format_floor_color(char *line, t_data *data)
{
	int		i;
	char	**rgb_tab;

	i = 0;
	rgb_tab = ft_split(line, 44);
	ft_print_tab(rgb_tab);
	ft_trim_tab(rgb_tab);
	ft_print_tab(rgb_tab);
	while (rgb_tab[i])
		i++;
	if (i != 3)
		ft_free_exit(line, rgb_tab, data, 1);
	i = 0;
	while (i < 3)
	{
		if (!ft_is_number(rgb_tab[i]))
			ft_free_exit(line, rgb_tab, data, 2);
		data->config.floor_color[i] = ft_atoi(rgb_tab[i]);
		i++;
	}
	data->config.metadata_count++;
	free(line);
	free_char_tab(rgb_tab);
	return (0);
}

int	check_config_data(t_data *data)
{
	check_texture(data);
	check_colors(data);
	return (0);
}

int	check_texture(t_data *data)
{
	int	i;
	int	fd;

	i = 0;
	while (i < 4)
	{
		fd = open(data->config.textures[i], O_RDONLY);
		data->config.textures_files_fd[i] = fd;
		if (fd == -1)
		{
			printf("\033[31mError\n:Issue with one of the texture.\nTexture File name : |%s|\n%s\033[0m\n",
				data->config.textures[i], strerror(errno));
			ft_clean_data_and_exit(data);
		}
		printf("\033[32m Texture file OK \n|%s|\n\033[0m\n",
			data->config.textures[i]);
		i++;
	}
	return (0);
}

int	check_colors(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (data->config.ceiling_color[i] < 0
			|| data->config.ceiling_color[i] > 255)
		{
			printf("\033[31mError\n:Issue with the RGB ceiling color.\n%s\033[0m\n",
				strerror(errno));
			ft_clean_data_and_exit(data);
		}
		printf("\033[32mRGB ceiling color OK \n%d\n\033[0m\n",
			data->config.ceiling_color[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (data->config.floor_color[i] < 0
			|| data->config.floor_color[i] > 255)
		{
			printf("\033[31mError\n:Issue with the RGB floor color :%d\n\033[0m\n", data->config.floor_color[i]);
			ft_clean_data_and_exit(data);
		}
		printf("\033[32mRGB floor color OK \n%d\n\033[0m\n",
			data->config.floor_color[i]);
		i++;
	}
	return (0);
}
