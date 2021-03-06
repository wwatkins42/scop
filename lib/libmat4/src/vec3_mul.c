/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:06:56 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/10 13:43:47 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

t_vec3	vec3_mul(t_vec3 a, t_vec3 b)
{
	int	i;

	i = -1;
	while (++i < 3)
		a.v[i] *= b.v[i];
	return (a);
}
