/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:50:22 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/12/08 17:35:13 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

static const t_parsermap	g_parsers[] = {
{"A", parse_ambient},
{"C", parse_camera},
{"L", parse_light},
{"sp", parse_sphere},
{"pl", parse_plane},
{"cy", parse_cylinder},
{NULL, NULL}
};

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

int	parse_line(char *line, t_scene *scene)
{
	char	**tokens;
	int		i;

	if (!ft_strchr(line, ' '))
		return (printf("Error\nElements not separated by spaces\n"), 0);
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (printf("Error\nMalloc failed\n"), 0);
	i = 0;
	while (g_parsers[i].id)
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
	{
		printf("Error\nUnknown identifier '%s'\n", tokens[0]);
		return (free_array(tokens), 0);
	}
	return (free_array (tokens), 1);
}

int	handle_line(char *new_line, t_scene *scene)
{
	char	*line;

	if (new_line[0] == '\n')
		return (1);
	line = ft_strtrim(new_line, "\n");
	if (!line)
		return (printf("Error\nMalloc error\n"), 0);
	if (!parse_line(line, scene))
		return (free(line), 0);
	return (free(line), 1);
}

int	read_file(char *argv[], t_scene *scene)
{
	int		fd;
	char	*new_line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error\n%s\n", strerror(errno)), 0);
	new_line = get_next_line(fd);
	while (new_line != NULL)
	{
		if (!handle_line(new_line, scene))
		{
			free (new_line);
			close(fd);
			return (0);
		}
		free(new_line);
		new_line = get_next_line(fd);
	}
	free(new_line);
	close(fd);
	return (1);
}
