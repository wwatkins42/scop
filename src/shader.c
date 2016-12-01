/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:53:46 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/01 12:56:25 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/* Get the source code of the specified shader file.
*/
const GLchar	*get_shader_source(char *filename)
{
	int		fd;
	int		ret;
	char	buffer[BUFFER_SIZE];
	char	*source;

	source = (GLchar*)malloc(sizeof(GLchar) * BUFFER_SIZE + 1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		source = ft_strjoin(source, buffer);
	}
	close(fd);
	return (source);
}

/*	Create an OpenGL shader from "filename" and with "shaderType" defining the
	type of shader from GL_VERTEX_SHADER, GL_FRAGMENT_SHADER, ...
*/
GLuint	create_shader(char *filename, int shaderType)
{
	GLint			success;
	GLchar			infoLog[512];
	GLuint			shader;
	const GLchar	*shaderSource;

	shaderSource = get_shader_source(filename);
	shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderSource, NULL);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		printf("ERROR: shader (%s) compilation failed:\n%s", filename, infoLog);
		exit(0);
	}
	return (shader);
}

/*	Create a shader program compiled using a vertex shader and a
	fragment shader.
*/
GLuint	create_shader_program(GLuint vertexShader, GLuint fragmentShader)
{
	GLint	success;
	GLchar	infoLog[512];
	GLuint	shaderProgram;

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		printf("ERROR: shader program compilation failed:\n%s", infoLog);
		exit(0);
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	return (shaderProgram);
}

/*	Build the shader program from a filename for the vertex glsl shader file
	and one for the fragment glsl shader file.
*/
void	build_shader_program(t_env *env, char *v_file, char *f_file)
{
	GLuint	shader_vertex;
	GLuint	shader_fragment;

	shader_vertex = create_shader(v_file, GL_VERTEX_SHADER);
	shader_fragment = create_shader(f_file, GL_FRAGMENT_SHADER);
	env->shader.program = create_shader_program(shader_vertex, shader_fragment);
}
