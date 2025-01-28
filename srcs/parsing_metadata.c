/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_metadata.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:54:36 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/28 17:48:17 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"

int	parse_metadata(t_data *data, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (1);
		else if (ft_strncmp("NO ", line, 3) == 0)
		{
			data->config.textures[0] = ft_substr(line, 3, ((int)ft_strlen(line)));
			printf("Path = |%s|\n", data->config.textures[0]);
			for (int i = 0; line[i] != '\0'; i++) {
    		printf("Char: '%c', Hex: 0x%x, Index: %d\n", line[i], line[i], i);
}
		}
		else if (ft_strncmp("SO ", line, 3) == 0)
			data->config.textures[1] = ft_substr(line, 3, ft_strlen(line));
		else if (ft_strncmp("WE ", line, 3) == 0)
			data->config.textures[2] = ft_substr(line, 3, ft_strlen(line));
		else if (ft_strncmp("EA ", line, 3) == 0)
			data->config.textures[3] = ft_substr(line, 3, ft_strlen(line));
		else if (ft_strncmp("F ", line, 2) == 0)
			format_color(line, data);
		else if (ft_strncmp("C ", line, 2) == 0)
			format_color(line, data);
		else
			continue ;
		free(line);
	}
}

int	format_color(char *line, t_data *data)
{
	int		i;
	char	**rgb_tab;

	i = 0;
	rgb_tab = ft_split(line, 44);
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		rgb_tab[i] = ft_substr(rgb_tab[i], 2, ft_strlen(rgb_tab[i]));
		while (i < 3)
		{
			printf("rgb_tab[i] = %s\n", rgb_tab[i]);
			printf("data->config.floor_color[i] = %d\n", ft_atoi(rgb_tab[i]));
			fflush(0);
			data->config.floor_color[i] = ft_atoi(rgb_tab[i]);
			i++;
		}
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		rgb_tab[i] = ft_substr(rgb_tab[i], 2, ft_strlen(rgb_tab[i]));
		while (i < 3)
		{
			printf("rgb_tab[i] = %s\n", rgb_tab[i]);
			printf("data->config.ceiling_color[i] = %d\n", ft_atoi(rgb_tab[i]));
			fflush(0);
			data->config.ceiling_color[i] = ft_atoi(rgb_tab[i]);
			i++;
		}
	}
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
		printf("|%s|\n", data->config.textures[i]);
		fd = open(data->config.textures[i], O_RDONLY);
		printf("./Textures/Bricks/BIGBRICKS.png\n");
		printf("Open = %d\n", fd);
		fd = open("./Textures/Bricks/BIGBRICKS.png", O_RDONLY);
		printf("Open = %d\n", fd);
		if (fd != -1)
			printf("OKOKOKOK\n");
		if (fd == -1)
		{
			printf("\033[31mError\n:Issue with one of the texture.\n%s\033[0m\n",
				strerror(errno));
			exit(1);
		}
		printf("\033[32m Texture file OK\033[0m\n");
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
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (data->config.floor_color[i] < 0
			|| data->config.floor_color[i] > 255)
		{
			exit(printf("\033[31mError\n:Issue with the RGB floo color.\n%s\033[0m\n",
					strerror(errno)));
		}
		i++;
	}
	return (0);
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
