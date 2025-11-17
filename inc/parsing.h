/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:50:23 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/17 16:16:17 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "miniRT.h"

typedef int (*t_parser_func)(char **tokens, t_scene *scene);

typedef struct s_parsermap
{
	char			*id;
	t_parser_func	func;	
}	t_parsermap;

int		parse_ambient(char **tokens, t_scene *scene);
int		parse_camera(char **tokens, t_scene *scene);
int		parse_light(char **tokens, t_scene *scene);
int		parse_sphere(char **tokens, t_scene *scene);
int		parse_plane(char **tokens, t_scene *scene);
int		parse_cylinder(char **tokens, t_scene *scene);
void	free_scene(t_scene *scene);
double	str_to_double(char *str);
int		str_to_rgb(char *str, t_rgb *rgb);
int		check_double(char *str);
int		check_rgb(char *str);
int		parse_vector(char *str, t_vec3	*vec);
void	free_array(char **array);
int		parse_norm_vector(char*str, t_vec3	*vec);

#endif
