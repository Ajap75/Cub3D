/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:26:31 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/05 17:44:32 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"

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

int	check_ceiling_color(t_data *data)
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
	return (0);
}

int	check_floor_color(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (data->config.floor_color[i] < 0
			|| data->config.floor_color[i] > 255)
		{
			printf("\033[31mError\n:Issue with the RGB floor color :%d\n\033[0m\n",
				data->config.floor_color[i]);
			ft_clean_data_and_exit(data);
		}
		printf("\033[32mRGB floor color OK \n%d\n\033[0m\n",
			data->config.floor_color[i]);
		i++;
	}
	return (0);
}

int	check_colors(t_data *data)
{
	check_ceiling_color(data);
	check_floor_color(data);
	return (0);
}
