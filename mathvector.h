#ifndef MATHVECTOR_H
#define MATHVECTOR_H
#define _USE_MATH_DEFINES
#include <cmath>

struct math_vector
{
	float x, y, z;

	math_vector() : x(0.0f), y(0.0f), z(0.0f) {}

	math_vector(float a, float b, float c) : x(a), y(b), z(c) {}

	float magnitude() const
	{
		return sqrt(x*x + y*y + z*z);
	}

	float dot(const math_vector &v) const
	{
		return (x*v.x + y*v.y + z*v.z);
	}

	math_vector& operator= (const math_vector &v)
	{
		x = v.x; y = v.y; z = v.z;
		return *this;
	}

	math_vector operator- () const
	{
		return math_vector(-x, -y, -z);
	}

	math_vector operator+ (const math_vector &v) const
	{
		return math_vector(x + v.x, y + v.y, z + v.z);
	}

	math_vector& operator+= (const math_vector &v)
	{
		x += v.x, y += v.y, z += v.z;
		return *this;
	}

	math_vector operator- (const math_vector &v) const
	{
		return math_vector(x - v.x, y - v.y, z - v.z);
	}

	math_vector& operator-= (const math_vector &v)
	{
		x -= v.x, y -= v.y, z -= v.z;
		return *this;
	}

	math_vector operator* (float a) const
	{
		return math_vector(x*a, y*a, z*a);
	}

	math_vector operator*= (float a)
	{
		x *= a, y *= a, z *= a;
		return *this;
	}

	math_vector normal() const
	{
		float norm = 1.0f;
		if (x || y || z)
			norm /= magnitude();
		return (*this) * norm;
	}

	math_vector cross(const math_vector &v) const
	{
		return math_vector(
			y*v.z - z*v.y,
			z*v.x - x*v.z,
			x*v.y - y*v.x
			);
	}

	math_vector slerp(const math_vector &ve, float t) const
	{
		if (t <= 0.0f)
			return (*this);
		else if (t >= 1.0f)
			return ve;

		float prod = dot(ve);
		if (abs(prod) >= 1.0f)
			return (*this);

		float theta = acos(prod);
		float sth = sin(theta);
		float fa = sin((1-t)*theta)/sth;
		float fb = sin(t*theta)/sth;
	
		return math_vector(
		x*fa + ve.x*fb,
		y*fa + ve.y*fb,
		z*fa + ve.z*fb
		);
	}
};

#endif