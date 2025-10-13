/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:00:37 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/10/13 16:34:03 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

int	get_rgba(int r, int g, int b, int a);

#endif