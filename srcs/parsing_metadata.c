/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_metadata.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:54:36 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/28 12:38:30 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"

int	parse_metadata(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (1)
	{
		if (line == NULL)
			return (1);
		else if (ft_strncmp(line, "NO ", 3) == 0)
			data->config.textures[0] = ft_substr(line, 3, sizeof(line));
		else if (ft_strncmp(line, "SO ", 3) == 0)
			data->config.textures[1] = ft_substr(line, 3, sizeof(line));
		else if (ft_strncmp(line, "WE ", 3) == 0)
			data->config.textures[2] = ft_substr(line, 3, sizeof(line));
		else if (ft_strncmp(line, "EA ", 3) == 0)
			data->config.textures[3] = ft_substr(line, 3, sizeof(line));
		else if (ft_strncmp(line, "F ", 2) == 0)
			format_color(line, data);
		else if (ft_strncmp(line, "C ", 2) == 0)
			format_color(line, data);
	}
}

void	format_color(char *line, t_data *data)
{
	int		i;
	char	**rgb_tab;

	i = 0;
	rgb_tab = ft_split(line, 32);
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		while (i < 3)
			data->config.floor_color[i] = ft_atoi(rgb_tab[i]);
		i++;
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		while (i < 3)
			data->config.ceiling_color[i] = ft_atoi(rgb_tab[i]);
		i++;
	}
	return ;
}

void	check_config_data(t_data *data)
{
	check_texture(data);
	check_colors(data);
}

void	check_texture(t_data *data)
{
	int	i;
	int	fd;

	i = 0;
	while (i < 4)
	{
		fd = open(data->config.textures[i], O_RDONLY);
		if (fd)
		{
			printf("\033[31mError\n:Issue with one of the texture\033[0m\n",
				strerror(errno));
			Exit(1);
		}
		printf("E\033[32m Texture file OK\033[0m\n", strerror(errno));
		i++;
	}
}

void	check_colors(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (data->config.ceiling_color[i] < 0
			|| data->config.ceiling_color[i] > 255)
		{
			printf("\033[31mError\n:Issue with the RGB ceiling color\033[0m\n",
				strerror(errno));
			Exit(1);
		}
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (data->config.floor_color[i] < 0
			|| data->config.floor_color[i] > 255)
		{
			exit(printf("\033[31mError\n:Issue with the RGB floo color\033[0m\n",
					strerror(errno)));
		}
		i++;
	}
}

// void	free_data(t_data *data)
// {
// 	int i;
// 	i = 0;
// 	while (i < 3)
// 	{
// 		if (data->config.ceiling_color[i])
// 			free(data->config.ceiling_color[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 3)
// 	{
// 		if (data->config.floor_color[i])
// 			free(data->config.ceiling_color[i]);
// 		i++;
// 	}
// 	i = 0;

// }
