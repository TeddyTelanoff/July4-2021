#pragma once

#include "Util.h"
#include <GLES3/gl3.h>

struct Shader
{
	GLuint prog;

	Shader(const char *vert, const char *frag)
	{
		prog = glCreateProgram();
		GLuint vs = CompileShader(GL_VERTEX_SHADER, vert);
		GLuint fs = CompileShader(GL_FRAGMENT_SHADER, frag);

		glAttachShader(prog, vs);
		glAttachShader(prog, fs);
		glLinkProgram(prog);
		glValidateProgram(prog);

		glDeleteShader(vs);
		glDeleteShader(fs);
	}

	void Bind() const
	{ glUseProgram(prog); }

	void SetUniform(GLint loc, Vector2 vec2)
	{ glUniform2f(loc, vec2.x, vec2.y); }

	static GLuint CompileShader(GLenum ty, const char *src)
	{
		GLuint id = glCreateShader(ty);
		glShaderSource(id, 1, &src, NULL);
		glCompileShader(id);

		GLint status;
		glGetShaderiv(id, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE)
		{
			GLsizei len;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);

			GLchar *msg = (GLchar *)alloca(len * sizeof(GLchar));
			glGetShaderInfoLog(id, len, NULL, msg);
			Throw(msg);
			
			glDeleteShader(id);
			return NULL;
		}

		return id;
	}
};
