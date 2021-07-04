#pragma once

#include "Math.h"

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
	Mesh meshes[RT::Count];

	void Render(RenderType ty, Vector2 pos, Vector2 scale)
	{
		meshes[ty].Bind();
		meshes[ty].shader;
	}
};
