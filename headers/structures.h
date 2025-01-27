/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:42:38 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/27 18:00:01 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_config
{
	char		*textures[4];

	int Ifloor_color[3];  /* RGB */
	int ceiling_color[3]; // RGB
}				t_config;

typedef struct s_map
{
	char **layout;   // 2D array for the map
	int width;       // Map width
	int height;      // MAp height
	int player_x;    // player coordinate
	int player_y;    // player coordinate
	char player_dir; // player starting orientation
}				t_map;

typedef struct s_data
{
	t_config	config;
	t_map		mpa;
}				t_data;

#endif
