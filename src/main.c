/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:20:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/03 12:56:42 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

GLfloat cubeVertices[] = {
	/* Positions */        /* Colors */
	-0.1f,  0.1f, 0.0f,  0.0f, 1.0f, 0.0f, // 0
	 0.1f,  0.1f, 0.0f,  0.0f, 0.0f, 1.0f, // 1
	 0.1f, -0.1f, 0.0f,  1.0f, 0.0f, 0.0f, // 2
	-0.1f, -0.1f, 0.0f,  0.0f, 1.0f, 1.0f, // 3
	-0.1f,  0.1f, 0.2f,  0.0f, 1.0f, 0.0f, // 4
	 0.1f,  0.1f, 0.2f,  0.0f, 0.0f, 1.0f, // 5
	 0.1f, -0.1f, 0.2f,  1.0f, 0.0f, 0.0f, // 6
	-0.1f, -0.1f, 0.2f,  0.0f, 1.0f, 1.0f  // 7
};

GLuint	cubeIndices[] = {
	/*	A cube has 6 faces, with 2 triangles/face, so 12 triangles total. */
	0, 1, 2,  0, 3, 2,  0, 4, 5,  0, 1, 5,  0, 4, 7,  0, 3, 7,
	6, 2, 1,  6, 5, 1,  6, 5, 4,  6, 7, 4,  6, 2, 3,  6, 7, 3
};

int		main(void)
{
	t_env	env;

	env.win.w = 1280;
	env.win.h = 960;
	env.win.ratio = env.win.w / (float)env.win.h;
	init_glfw_env();
	init_glfw_win(&env, env.win.w, env.win.h);

	/*	Create the key callback */
	glfwSetKeyCallback(env.win.ptr, key_callback);
	/*	Build and compile our shader program */
	build_shader_program(&env, "../shader/vertex.glsl", "../shader/fragment.glsl");
	/*	Create the objects buffers for the differents objects
		(vertex_buffer, vertex_array, element_buffer) */
	env.data.size_vertices = sizeof(cubeVertices);
	env.data.size_indices = sizeof(cubeIndices);
	create_buffers(&env, cubeVertices, cubeIndices, GL_DYNAMIC_DRAW);
	/*	Prevents stange bugs */
	glBindVertexArray(0);

	float m_mat[16];
	float v_mat[16];
	float p_mat[16];

	set_model_matrix(m_mat);
	set_view_matrix(v_mat);
	set_projection_matrix(p_mat, 60, env.win.ratio, 0.01f, 100.0f);
	mat4_print(m_mat);
	mat4_print(v_mat);
	mat4_print(p_mat);

	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	while(!glfwWindowShouldClose(env.win.ptr))
	{
		/*	Events handler */
		glfwPollEvents();

		/*	Clears the color buffer */
		glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/*	Uniform test for color changing of the fragment shader */
		GLfloat	timeValue = glfwGetTime();
		GLfloat B = (sin(timeValue) / 2) + 0.5;
		GLfloat G = (sin(timeValue - 1.5) / 2) + 0.5;
		GLfloat	R = (cos(timeValue) / 2) + 0.5;
		GLint	vertexColorLocation = glGetUniformLocation(env.shader.program, "mod_color");


		GLint	modelLoc = glGetUniformLocation(env.shader.program, "model");
		GLint	viewLoc = glGetUniformLocation(env.shader.program, "view");
		GLint	projectionLoc = glGetUniformLocation(env.shader.program, "projection");

		// m_mat[11] = (sin(timeValue) / 2) - 0.5;

		translate(m_mat, sin(timeValue) * 0.001, 0, 0);
		// scale(m_mat, -0.01, -0.01, -0.01);
		// scale(m_mat, -0.01, -0.01, -0.01);
		// mat4_rotate_axis(m_mat, AXIS_X, sin(timeValue * 0.2));
		// mat4_rotate_axis(m_mat, AXIS_Y, sin(timeValue * 0.2));
		// mat4_rotate_axis(m_mat, AXIS_Z, sin(timeValue * 0.2));
		mat4_print(m_mat);

		/*	Activate the shader program */
		glUseProgram(env.shader.program);
		/*	Updates the uniform variable in the fragment shader */
		glUniform4f(vertexColorLocation, R, G, B, 1.0f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, m_mat);
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, v_mat);
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, p_mat);

		/*	Draw our rectangle using the shader program */
		glBindVertexArray(env.buffer.VAO);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0); // 36 is num of indices
		glBindVertexArray(0);

		/*	Swap the screen buffers (to display on screen the computed image) */
		glfwSwapBuffers(env.win.ptr);
	}
	clean_glfw(&env);
	return (0);
}
