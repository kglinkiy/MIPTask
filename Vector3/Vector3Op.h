#pragma once

#include "Vector3.h"

// These two files are not detailed out in this blog post.

namespace VectMath
{
	Scalar len(const Vector3& vect);
	Scalar len2(const Vector3& vect);

	void Clamp(Vector3& vect, Scalar length);
	void Normalize(Vector3& vect);
	void Normalize_s(Vector3& vect);
	void SetLength(Vector3& vect, Scalar length);
	void SetLength_s(Vector3& vect, Scalar length);

	Scalar  ScalMult(const Vector3& vec1, const Vector3& vec2);
	Scalar  GetAngle(Vector3 vec1, Vector3 vec2);

	Vector3 ToNormalized(const Vector3& vect);
	Vector3 ToNormalized_s(const Vector3& vect);
	Vector3 VectMult(const Vector3& vec1, const Vector3& vec2);
	Scalar  MixedMult(const Vector3& vec1, const Vector3& vec2, const Vector3& vec3);
	Vector3 Rotate( Vector3& vec1, Scalar angle,  Vector3& axis);
		
	inline Scalar len(const Vector3& vect)
	{
		return sqrt(vect.X * vect.X + vect.Y * vect.Y + vect.Z * vect.Z);
	}

	inline Scalar len2(const Vector3& vect)
	{
		return vect.X * vect.X + vect.Y * vect.Y + vect.Z * vect.Z;
	}

	inline void Normalize(Vector3& vect)
	{
		vect /= len(vect);
	}

	inline void SetLength(Vector3& vect, Scalar length)
	{
		vect *= length / len(vect);
	}

	inline Scalar  ScalMult(const Vector3& vec1, const Vector3& vec2)
	{
		return vec1.X * vec2.X + vec1.Y * vec2.Y + vec1.Z * vec2.Z;
	}

	inline Vector3 ToNormalized(const Vector3& vect)
	{
		return vect / len(vect);
	}

	
	inline Scalar  MixedMult(const Vector3& vec1, const Vector3& vec2, const Vector3& vec3) {
		return  ScalMult(vec1, VectMult(vec2, vec3));
	}
	

	inline Vector3  VectMult(const Vector3& vec1, const Vector3& vec2)
	{
		return Vector3(
			vec1.Y * vec2.Z - vec1.Z * vec2.Y,
			vec1.Z * vec2.X - vec1.X * vec2.Z,
			vec1.X * vec2.Y - vec1.Y * vec2.X);
	}
	
}
