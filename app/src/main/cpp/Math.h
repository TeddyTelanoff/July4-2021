#pragma once

struct Vector3
{
	float x, y, z;

	Vector3 operator +(const Vector3 &o) const
	{ return { x + o.x, y + o.y, z + o.z, }; }

	Vector3 operator -(const Vector3 &o) const
	{ return { x - o.x, y - o.y, z - o.z, }; }

	Vector3 operator *(const Vector3 &o) const
	{ return { x * o.x, y * o.y, z * o.z, }; }

	Vector3 operator /(const Vector3 &o) const
	{ return { x / o.x, y / o.y, z / o.z, }; }

	Vector3 operator *(float n) const
	{ return { x * n, y * n, z * n, }; }

	Vector3 operator /(float n) const
	{ return { x / n, y / n, z / n, }; }
};

struct Matrix4
{
	float data[16] = {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1,
	};

	void Translate(Vector3);
};