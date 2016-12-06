/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:51:00 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/06 16:55:56 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	key_handle(t_env *env)
{
	int	i;

	if (glfwGetKey(env->win.ptr, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(env->win.ptr, GL_TRUE);
	i = -1;
	while (++i < MAX_KEYS)
		env->key.code[i] = glfwGetKey(env->win.ptr, i) == GLFW_PRESS ? 1 : 0;
	key_action(env);
}

void	key_action(t_env *env)
{
	if (env->key.code[ZP] || env->key.code[ZM])
		camera_zoom(env);
	// camera_move(env, LOCKED);
	camera_move_inertia(env, 0.93, LOCKED);
	camera_look_at_target(env);
	if (glfwGetKey(env->win.ptr, GLFW_KEY_I) == GLFW_PRESS)
		rotate(&env->model.rotation, (t_vec3) { 2, 0, 0 });
	if (glfwGetKey(env->win.ptr, GLFW_KEY_K) == GLFW_PRESS)
		rotate(&env->model.rotation, (t_vec3) { -2, 0, 0 });
	if (glfwGetKey(env->win.ptr, GLFW_KEY_J) == GLFW_PRESS)
		rotate(&env->model.rotation, (t_vec3) { 0, -2, 0 });
	if (glfwGetKey(env->win.ptr, GLFW_KEY_L) == GLFW_PRESS)
		rotate(&env->model.rotation, (t_vec3) { 0, 2, 0 });
}
