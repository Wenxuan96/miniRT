/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:18:25 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/22 11:25:53 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	string_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i ++;
	}
	free(array);
}

static char	**create_array(char const *s, char c, char **array, int n)
{
	int		i;
	int		end;
	int		begin;

	i = 0;
	end = 0;
	while (i < n && s[end])
	{
		if (s[end] != c && (s[end + 1] == c || s[end + 1] == '\0'))
		{
			begin = end;
			while (s[begin - 1] != c && begin > 0)
				begin --;
			array[i] = ft_substr(s, begin, (end - begin +1));
			if (array[i] == NULL)
			{
				free_array(array);
				return (NULL);
			}
			i ++;
		}
		end ++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array_of_strings;
	int		number_of_arrays;

	number_of_arrays = string_count(s, c);
	array_of_strings = malloc((number_of_arrays + 1) * sizeof(char *));
	if (array_of_strings == NULL)
		return (NULL);
	array_of_strings = create_array(s, c, array_of_strings, number_of_arrays);
	return (array_of_strings);
}

//#include <stdio.h>

//int	main (void)
//{
//	char	str[] = "hoihoi";
//	char	c;
//	char	**array;
//	int		i;

//	i = 0;
//	c = 'i';
//	array = ft_split(str,c);
//	printf("the number of strings is %d\n", string_count(str, c));
//	while (i < string_count(str,c))
//	{
//		printf("%s\n", array[i]);
//		i++;
//	}
//	return(0);
//}