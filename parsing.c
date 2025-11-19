/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:07:10 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/19 14:44:46 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/parsing.h"

static const	t_parsermap g_parsers[] =
{
	{"A", parse_ambient},
	{"C", parse_camera},
	{"L", parse_light},
	{"sp", parse_sphere},
	{"pl", parse_plane},
	{"cy", parse_cylinder},
	{NULL, NULL}
};

void	init_scene(t_scene *scene)
{
	scene->ambient = (t_ambient){0};
	scene->camera = (t_camera){0};
	scene->light = (t_light){0};
	scene->has_ambient = false;
	scene->has_camera = false;
	scene->has_light = false;
	scene->objects = NULL;
}

int	parse_line(char *line, t_scene *scene)
{
	char	**tokens;
	int		i;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (printf("Error\nMalloc failed\n"), 0);
	i = 0;
	while(g_parsers[i].id)
	{
		if (ft_strncmp(tokens[0], g_parsers[i].id, ft_strlen(tokens[0])) == 0)
		{
			if (!g_parsers[i].func(tokens, scene))
				return (free_array(tokens), 0);
			break ;
		}
		i++;
	}
	if (g_parsers[i].id == NULL)
		return (printf("Error\nUnknown identifier '%s'\n", tokens[0]), 0);
	i = 0;
	free_array(tokens);
	return (1);
}

int	check_file_extension(char *argv)
{
	char	*ext;

	ext = ft_strchr(argv, '.');
	if (!ext || ft_strlen(ext) != 3 || ft_strncmp(ext, ".rt", 3) != 0)
	{
		printf("Error\nInvalid file extension, use .rt file\n");
		return (0);
	}
	return (1);
}

void	del_node(void *content)
{
	free(content);
}

void	free_scene(t_scene *scene)
{
	ft_lstclear(&scene->objects, del_node);
	free(scene);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*new_line;
	char	*line;
	t_scene	*scene;
	
	if (argc != 2)
	{
		printf("Error\nPlease input .rt file\n");
		return (1);
	}
	if (!check_file_extension(argv[1]))
		return(1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n%s\n", strerror(errno));
		return (1);
	}
	scene = ft_calloc(1, sizeof(* scene));
	if (!scene)
		return(printf("Error\nMalloc error\n"), 1);
	init_scene(scene);
	while((new_line = get_next_line(fd)) != NULL)
	{
		if(new_line[0] == '\n')
		{
			free(new_line);
			continue ;
		}
		line = ft_strtrim(new_line, "\n");
		if (!parse_line(line, scene))
		{
			free (line);
			free (new_line);
			return(free_scene(scene), 1);
		}
		free(line);
		free(new_line);
	}
	close(fd);
	//print scene for testing
	free_scene(scene);
	return(0);
}
