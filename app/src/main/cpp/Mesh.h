#pragma once

#include "Renderer.h"
#include "Shader.h"
#include <GLES3/gl3.h>

struct Mesh
{
	const Shader &shader;
	GLuint vao, ibo;

	static constexpr GLfloat verts[] = {
		0, 0,
		1, 0,
		1, 1,
		0, 1,
	};

	static constexpr GLuint inds[] = {
		0, 1, 2,
		0, 2, 3,
	};

	Mesh(const Shader &shader):
		shader(shader)
	{
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_TRUE, 8, 0);

		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(inds), inds, GL_STATIC_DRAW);
	}

	void Bind()
	{
		glBindVertexArray(vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	}
};
