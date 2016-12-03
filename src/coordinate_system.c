/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_system.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:27:51 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/03 12:56:48 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	set_model_matrix(float *m)
{
	mat4_set(m, IDENTITY);
}

void	set_view_matrix(float *m)
{
	mat4_set(m, IDENTITY);
}

void	set_projection_matrix(float *m, float fov, float ratio, float near, float far)
{
	float	s;

	s = 1 / (tan(fov * 0.5 * M_PI / 180.0));
	mat4_set(m, 0);
	m[0] = s / ratio;
	m[5] = s;
	m[10] = -(far + near) / (far - near);
	m[11] = -1;
	m[14] = -2 * far * near / (far - near);
	m[15] = 1;
}
