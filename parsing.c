/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:07:10 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/06 17:43:40 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/parsing.h"

static const t_parsermap g_parsers[] =
{
	{"A", parse_ambient},
	{"C", parse_camera},
	{"L", parse_light},
	{"sp", parse_sphere},
	{"pl", parse_plane},
	{"cy", parse_cylinder},
	{NULL, NULL}
};

int	check_line(char *line)
{
	char	**tokens;
	int		i;

	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		printf("Error\nMalloc failed\n");
		return(0);
	}
	i = 0;
	while(g_parsers[i].id)
	{
		if (ft_strncmp(tokens[0], g_parsers[i].id, 1) == 0)
		{
			g_parsers[i].func(tokens);
			break ;
		}
		i++;
	}
	if (g_parsers[i].id == NULL)
		printf("Error\nUnknown identifier '%s'\n", tokens[0]);
	i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
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

int	main(int argc, char *argv[])
{
	int		fd;
	char	*new_line;
	char	*line;
	
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
	while((new_line = get_next_line(fd)) != NULL)
	{
		if(new_line[0] == '\n')
		{
			free(new_line);
			continue ;
		}
		line = ft_strtrim(new_line, "\n");
		printf("%s\n", line);
		check_line(line);
		free(line);
		free(new_line);
	}
	close(fd);
	return(0);
}
