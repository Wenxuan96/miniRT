/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:50:23 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/27 13:11:38 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "miniRT.h"
# include "../libft/libft.h"
# include "objects.h"

typedef int	(*t_parser_func)(char **tokens, t_world *scene);

typedef struct s_parsermap
{
	char			*id;
	t_parser_func	func;	
}	t_parsermap;

int		parse_ambient(char **tokens, t_world *scene);
int		parse_camera(char **tokens, t_world *scene);
int		parse_light(char **tokens, t_world *scene);
int		parse_sphere(char **tokens, t_world *scene);
int		parse_plane(char **tokens, t_world *scene);
int		parse_cylinder(char **tokens, t_world *scene);
void	free_scene(t_world *scene);
double	str_to_double(char *str);
int		str_to_rgb(char *str, t_rgb *rgb);
int		check_double(char *str);
int		check_rgb(char *str);
int		parse_tuple(char *str, t_tuple *tuple, double w);
void	free_array(char **array);
int		parse_norm_tuple(char*str, t_tuple	*tuple);
int		check_file_extension(char *argv);
int		parse_line(char *line, t_world *scene);
int		handle_line(char *new_line, t_world *scene);
int		read_file(char *argv[], t_world *scene);
void	init_world(t_world *scene);
void	free_scene(t_world *scene);
int		check_scene(t_world *scene);
int		check_tokens(char **tokens, int expected);
t_world	*parse(int argc, char *argv[]);
int		add_node(void *content, t_world *scene);
int		check_tokens(char **tokens, int expected);
int		init_base(t_object *base, t_obj_type type, t_rgb color);

#endif
