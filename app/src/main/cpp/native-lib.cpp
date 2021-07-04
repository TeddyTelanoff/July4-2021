#include <jni.h>
#include <cmath>
#include <GLES3/gl3.h>

uint LoadShader(uint ty, const char *src)
{
	uint shader = glCreateShader(ty);
	if (!shader)
		return 0;

	glShaderSource(shader, 1, &src, NULL);
	glCompileShader(shader);

	int status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (!status)
	{
		int len;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);

		char *info = (char *)alloca(len);
		glGetShaderInfoLog(shader, len, NULL, info);
		puts(info);

		glDeleteShader(shader);
		return 0;
	}

	return shader;
}

uint CreateShader()
{
	static char vertShader[] = "attribute vec4 pos; void main() { gl_Position = pos; }";
	static char fragShader[] = "precision mediump float; void main() { gl_FragColor = vec4(0, 1, 0, 1); }";

	uint vert = LoadShader(GL_VERTEX_SHADER, vertShader);
	uint frag = LoadShader(GL_FRAGMENT_SHADER, fragShader);

	uint prog = glCreateProgram();

	glAttachShader(prog, vert);
	glAttachShader(prog, frag);
	glBindAttribLocation(prog, 0, "pos");
	glLinkProgram(prog);

	int status;
	glGetProgramiv(prog, GL_LINK_STATUS, &status);
	if (!status)
	{
		int len;
		glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);

		char *info = (char *)alloca(len);
		glGetShaderInfoLog(prog, len, NULL, info);
		puts(info);

		glDeleteProgram(prog);
		return prog;
	}

	return prog;
}

extern "C" JNIEXPORT void JNICALL
Java_com_treidex_july4_MyRenderer_onSurfaceCreated(JNIEnv &env, jobject thiz,
	jobject gl, jobject config)
{
	float verts[] = {
		-0.5, -0.5,
		 0.5, -0.5,
		 0.5,  0.5,
		-0.5,  0.5,
	};

	uint inds[] = {
		0, 1, 2,
		0, 2, 3,
	};

	uint vao, vbo, ibo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_TRUE, 8, 0);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(inds), inds, GL_STATIC_DRAW);

	uint prog = CreateShader();
	glUseProgram(prog);

	glClearColor(0.25, 0.25, 0.25, 1);
}

extern "C" JNIEXPORT void JNICALL
Java_com_treidex_july4_MyRenderer_onSurfaceChanged(JNIEnv &env, jobject thiz,
	jobject gl, jint width, jint height)
{
	glViewport(0, 0, width, height);
}

extern "C" JNIEXPORT void JNICALL
Java_com_treidex_july4_MyRenderer_onDrawFrame(JNIEnv &env, jobject thiz,
	jobject gl)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
}