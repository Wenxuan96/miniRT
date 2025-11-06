/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:50:23 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/06 17:34:06 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "miniRT.h"

typedef int (*t_parser_func)(char **tokens);

typedef struct s_parsermap
{
	char			*id;
	t_parser_func	func;	
}	t_parsermap;

int	parse_ambient(char **tokens);
int	parse_camera(char **tokens);
int	parse_light(char **tokens);
int	parse_sphere(char **tokens);
int	parse_plane(char **tokens);
int	parse_cylinder(char **tokens);

#endif
