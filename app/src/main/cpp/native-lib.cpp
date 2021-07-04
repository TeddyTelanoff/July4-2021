#include <jni.h>
#include <GLES3/gl3.h>

#include "Renderer.h"

JNIEnv *env;
Renderer *renderer;

extern "C" JNIEXPORT void JNICALL
Java_com_treidex_july4_MyRenderer_onSurfaceCreated(JNIEnv *$env, jobject thiz,
	jobject gl, jobject config)
{
	env = $env;
	renderer = new Renderer;

	glClearColor(0.25, 0.25, 0.25, 1);
}

extern "C" JNIEXPORT void JNICALL
Java_com_treidex_july4_MyRenderer_onSurfaceChanged(JNIEnv *env, jobject thiz,
	jobject gl, jint width, jint height)
{
	glViewport(0, 0, width, height);
}

extern "C" JNIEXPORT void JNICALL
Java_com_treidex_july4_MyRenderer_onDrawFrame(JNIEnv *env, jobject thiz,
	jobject gl)
{
	glClear(GL_COLOR_BUFFER_BIT);
	renderer->Render(RT::Firework, { 0, 0 }, { 1, 1 });
}