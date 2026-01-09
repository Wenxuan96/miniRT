/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:50:23 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/07 18:59:30 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "miniRT.h"
# include "../libft/libft.h"

typedef int (*t_parser_func)(char **tokens, t_scene *scene);

typedef struct s_parsermap
{
	char			*id;
	t_parser_func	func;	
}	t_parsermap;

typedef enum	e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
} t_obj_type;

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
int		parse_tuple(char *str, t_tuple *tuple, double w);
void	free_array(char **array);
int		parse_norm_tuple(char*str, t_tuple	*tuple);
int		check_file_extension(char *argv);
int		parse_line(char *line, t_scene *scene);
int		handle_line(char *new_line, t_scene *scene);
int		read_file(char *argv[], t_scene *scene);
void	init_scene(t_scene *scene);
void	free_scene(t_scene *scene);
int		check_scene(t_scene *scene);
int		check_tokens(char **tokens, int	expected);
t_scene	*parse(int argc, char *argv[]);

#endif
