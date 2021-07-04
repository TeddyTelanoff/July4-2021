#pragma once

#include "Math.h"
#include "Mesh.h"

using RenderType = int;
namespace RT
{
	enum: RenderType
	{
		Sparkle,
		Firework,
		Smoke,

		Count,
	};
}

struct Renderer
{
	Shader *shader;
	Mesh *meshes[RT::Count];

	Renderer()
	{
		shader = new Shader("attribute vec4 pos; void main() { gl_Position = vec4(1) - pos; }","void main() { gl_FragColor = vec4(1, 0, 0, 1); }");

		for (auto &mesh : meshes)
			mesh = new Mesh;
	}

	void Render(RenderType ty, Vector2 pos, Vector2 scale)
	{
		meshes[ty]->Bind();
		shader->Bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
	}
};
