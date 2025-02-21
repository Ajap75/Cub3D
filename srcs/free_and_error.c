/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:11:17 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/21 13:05:41 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"

int	ft_free_exit(char *line, char **rgb_tab, t_data *data, int i)
{
	free(line);
	free_char_tab(rgb_tab);
	if (i == 1)
		printf("\033[31mError\n!RGB! Each color must be made of exactly 3 \
numbers serpareted by a coma\n\033[0m");
	else
		printf("\033[31mError\nDIGIT ONLY : Each color must be made of exactly 3 \
numbers serpareted by a coma\n\033[0m");
	return (ft_clean_data_and_exit(data));
}

int	free_char_tab(char **texture_file)
{
	int	i;

	i = 0;
	if (!texture_file)
		return (0);
	while (texture_file[i])
	{
		free(texture_file[i]);
		i++;
	}
	free(texture_file);
	return (1);
}

int	ft_clean_layout(t_data *data)
{
	int	i;

	i = 0;
	if (data == NULL || data->map.layout == NULL)
		return (1);
	while (i < data->map.height)
	{
		if (data->map.layout[i] != NULL)
			free(data->map.layout[i]);
		i++;
	}
	free(data->map.layout);
	data->map.layout = NULL;
	return (0);
}
int	ft_clean_data_and_exit(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(data->config.map_file_fd);
		if (line == NULL)
			break ;
		free(line);
	}
	while (i < 4)
	{
		if (data->config.textures_files_fd[i] != -1)
			close(data->config.textures_files_fd[i]);
		if (data->config.textures[i])
			free(data->config.textures[i]);
		i++;
	}
	ft_clean_layout(data);
	exit(1);
}
