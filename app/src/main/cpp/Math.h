#pragma once

struct Vector2
{
	float x, y;

	Vector2 operator +(const Vector2 &o) const
	{ return { x + o.x, y + o.y, }; }

	Vector2 operator -(const Vector2 &o) const
	{ return { x - o.x, y - o.y, }; }

	Vector2 operator *(const Vector2 &o) const
	{ return { x * o.x, y * o.y, }; }

	Vector2 operator /(const Vector2 &o) const
	{ return { x / o.x, y / o.y, }; }

	Vector2 operator *(float n) const
	{ return { x * n, y * n, }; }

	Vector2 operator /(float n) const
	{ return { x / n, y / n, }; }
};