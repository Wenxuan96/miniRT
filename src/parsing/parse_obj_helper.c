/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:54:08 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/27 12:54:11 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

int	add_node(void *content, t_world *scene)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (!node)
	{
		return (printf("Error\nMalloc error\n"), 0);
	}
	node->id = ft_lstsize(scene->objects) + 1;
	ft_lstadd_back(&scene->objects, node);
	return (1);
}

int	check_tokens(char **tokens, int expected)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	if (i != expected)
		return (printf("Error\nWrong amount of tokens\n"), 0);
	return (1);
}

int	init_base(t_object *base, t_obj_type type, t_rgb color)
{
	if (!base)
		return (0);
	base->type = type;
	base->color = color;
	base->transform = identity_m4();
	base->inv_transform = identity_m4();
	return (1);
}
