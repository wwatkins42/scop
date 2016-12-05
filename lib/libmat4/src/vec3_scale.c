/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:54:55 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/05 12:36:40 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

t_vec4 	vec3_scale(t_vec4 v, float f)
{
	int	i;

	vec3_normalize(v);
	i = -1;
	while (++i < 3)
		v.v[i] *= f;
	return (v);
}
