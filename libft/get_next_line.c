/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:57:02 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/04 15:04:22 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static char	*read_more(int fd, char *str)
{
	static char	buffer[BUFFER_SIZE +1];
	char		*new_size;
	ssize_t		read_length;

	while (!ft_strchr(str, '\n'))
	{
		read_length = read(fd, buffer, sizeof (buffer) - 1);
		if (read_length < 0)
			return (free (str), NULL);
		if (read_length == 0)
			break ;
		buffer[read_length] = '\0';
		new_size = ft_strjoin(str, buffer);
		if (new_size == NULL)
			return (free (str), NULL);
		free (str);
		str = new_size;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*full_str;
	char		*ret_str;
	int			length;
	static char	remain[BUFFER_SIZE];

	full_str = malloc((ft_strlen(remain) +1) * sizeof (char));
	if (!full_str)
		return (NULL);
	ft_strlcpy(full_str, remain, ft_strlen(remain) +1);
	full_str = read_more(fd, full_str);
	if (full_str == NULL || full_str[0] == '\0')
	{
		remain[0] = '\0';
		return (free (full_str), NULL);
	}
	if (!ft_strchr(full_str, '\n'))
		length = ft_strlen(full_str);
	else
		length = ft_strchr(full_str, '\n') - full_str +1;
	ret_str = ft_substr(full_str, 0, length);
	ft_strlcpy(remain, &full_str[length], ft_strlen(&full_str[length]) + 1);
	free (full_str);
	return (ret_str);
}
