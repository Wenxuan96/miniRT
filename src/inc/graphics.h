/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:00:37 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/27 13:09:00 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H
# include "../../MLX42/include/MLX42/MLX42.h"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

int		get_rgba(unsigned char r, unsigned char g,
			unsigned char b, unsigned char a);
void	put_image(void *param);

#endif