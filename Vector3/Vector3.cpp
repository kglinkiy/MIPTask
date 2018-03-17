//
//
#include "stdafx.h"
#include "Vector3.h"
#include "Vector3.h"
#include <limits>

namespace VectMath
{
	const Vector3 Vector3::Zero = Vector3(0, 0, 0);
	const Scalar Vector3::Epsilon = std::numeric_limits::epsilon();

	Vector3::Vector3()
	{
	}

	Vector3::Vector3(Scalar x, Scalar y, Scalar z){
			X = x;
			Y = y;
			Z = z;

	
	}

	Vector3& Vector3::operator+=(const Vector3& vector)
	{
		X += vector.X;
		Y += vector.Y;
		Z += vector.Z;
		return *this;
	}

	Vector3& Vector3::operator-=(const Vector3& vector)
	{
		X -= vector.X;
		Y -= vector.Y;
		Z -= vector.Z;
		return *this;
	}

	Vector3& Vector3::operator*=(Scalar num)
	{
		X *= num;
		Y *= num;
		Z *= num;
		return *this;
	}

	Vector3& Vector3::operator/=(Scalar num)
	{
		X /= num;
		Y /= num;
		Z /= num;
		return *this;
	}

