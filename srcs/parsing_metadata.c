/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_metadata.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:54:36 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/31 11:36:32 by anastruc         ###   ########.fr       */
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
}
int	ft_trim_tab(char **rgb_tab)
{
	int i;
	char *tmp;

	i = 0;
	if (rgb_tab)
	{
		while (rgb_tab[i])
		{
			tmp = rgb_tab[i];
			rgb_tab[i] = ft_strtrim(rgb_tab[i], " C F \t\n");
			free(tmp);
			i++;
		}
	}
	return (0);
}

void	ft_print_tab(char **rgb_tab)
{
	int	i;
	int	j;

	i = 0;
	while (rgb_tab[i])
	{
		j = 0;
		while (rgb_tab[i][j])
		{
			printf("rgb[%d][%d] = %d\n", i, j, rgb_tab[i][j]);
			j++;
		}
		i++;
	}
}


int	format_ceilling_color(char *line, t_data *data)
{
	int		i;
	char	**rgb_tab;

	// tmp = ft_strdup(line + 2);
	// free(line);
	// line = tmp;
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
	free(line);
	free_char_tab(rgb_tab);
	return (0);
}

int	ft_free_exit(char *line, char	**rgb_tab, t_data *data, int i)
{
	free(line);
	free_char_tab(rgb_tab);
	if (i == 1)
		printf("\033[31mError\n!RGB! Each color must be made of of exactly 3 \
numbers serpareted by a coma\n\033[0m");
	else
		printf("\033[31mError\nDIGIT ONLY : Each color must be made of exactly 3 \
numbers serpareted by a coma\n\033[0m");
	return(ft_clean_data_and_exit(data));
}

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	// if (str == NULL)
	// 	return
	while (str[i])
	{
	printf("str[%d] = %c\n", i, str[i]);
		if (ft_isdigit(str[i]))
			i++;
		else
		{
			return (0);
			printf("-----------\n");

		}
	}
	printf("-----------\n");
	return (1);
}

int	format_floor_color(char *line, t_data *data)
{
	int		i;
	char	**rgb_tab;
	// char	*tmp;

	// tmp = ft_strdup(line + 2);
	// free(line);
	// line = tmp;
	i = 0;
	rgb_tab = ft_split(line, 44);
	ft_print_tab(rgb_tab);
	ft_trim_tab(rgb_tab);
	ft_print_tab(rgb_tab);
	while (rgb_tab[i])
		i++;
	if (i != 3)
	{
		ft_free_exit(line, rgb_tab, data, 1);
	}
	i = 0;
	while (i < 3)
	{
		// rgb_tab[i] = ft_strtrim(rgb_tab[i], " C\t\n");
		if (!ft_is_number(rgb_tab[i]))
			ft_free_exit(line, rgb_tab, data, 2);
		data->config.floor_color[i] = ft_atoi(rgb_tab[i]);
		i++;
	}
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
			printf("\033[31mError\n:Issue with the RGB floor color : %d\
\033[0m\n", data->config.floor_color[i]);
		ft_clean_data_and_exit(data);
		}
		printf("\033[32mRGB floor color OK \n%d\n\033[0m\n",
			data->config.floor_color[i]);
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
