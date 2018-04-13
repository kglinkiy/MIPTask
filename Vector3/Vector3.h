#pragma once
#include <cmath>
#include <iostream>
namespace VectMath
{
	// могли бы просто сделать класс Vector3 шаблонным :)
	typedef float   Scalar;
	// fixit: зачем? есть же тип bool
	typedef int             Bool;

	class Vector3
	{
	public:
		Scalar X;
		Scalar Y;
		Scalar Z;

		Vector3();
		Vector3(Scalar x, Scalar y, Scalar z);

		Vector3  operator+(const Vector3& vector) const;
		Vector3  operator-(const Vector3& vector) const;
		Vector3  operator-() const;
		Vector3  operator*(Scalar num) const;
		Vector3  operator/(Scalar num) const;

		Vector3&    operator+=(const Vector3& vector);
		Vector3&    operator-=(const Vector3& vector);
		Vector3&    operator*=(Scalar num);
		Vector3&    operator/=(Scalar num);

		Bool        operator==(const Vector3& vector) const;
		Bool        operator!=(const Vector3& vector) const;

		static const Vector3 Zero;
		static const Scalar     Epsilon;
	};

	// fixit: зачем все это держать в h файле? перенесите в cpp
	inline Bool Vector3::operator==(const Vector3& vector) const
	{
		// не здорово так сравнивать вещественные числа, т.к. из-за ошибок округления может 0.9999(9) быть не равно 1.0, например
		return X == vector.X &&Y == vector.Y && Z == vector.Z;
	}

	inline Bool Vector3::operator!=(const Vector3& vector) const
	{
		// оператор != выразите через уже реализованный оператор ==
		return X != vector.X || Y != vector.Y || Z != vector.Z;
	}

	inline Vector3 Vector3::operator+(const Vector3& vector) const
	{
		return Vector3(X + vector.X, Y + vector.Y, Z + vector.Z);
	}

	inline Vector3 Vector3::operator-(const Vector3& vector) const
	{
		return Vector3(X - vector.X, Y - vector.Y, Z - vector.Z);
	}

	inline Vector3 Vector3::operator-() const
	{
		// можно выразить через operator*
		return Vector3(-X, -Y, -Z);
	}

	inline Vector3 Vector3::operator*(Scalar num) const
	{
		return Vector3(X * num, Y * num, Z * num);
	}

	inline Vector3 Vector3::operator/(Scalar num) const
	{
		// можно выразить через operator*
		return Vector3(X / num, Y / num, Z / num);
	}

}






