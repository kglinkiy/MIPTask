#pragma once
#include <cmath>
#include <iostream>
class Vector3{
public:
	class Vector3
	{
	public:
		typedef double Scalar;
		typedef int Bool;
		Scalar X;
		Scalar Y;
		Scalar Z;

		Vector3();
		Vector3(Scalar x, Scalar y, Scalar z);
		//Batch 1 arithmetic
		Vector3 operator+(const Vector3& vector) const;
		Vector3 operator-(const Vector3& vector) const;
		Vector3 operator-() const;
		Vector3 operator*(Scalar num) const;
		Vector3 operator/(Scalar num) const;
		//Batch 2 logical
		Vector3&   operator+=(const Vector3& vector);
		Vector3&   operator-=(const Vector3& vector);
		Vector3&   operator*=(Scalar num);
		Vector3&   operator/=(Scalar num);
		//equivalence operators
		Bool       operator==(const Vector3& vector) const;
		Bool       operator!=(const Vector3& vector) const;
		//batch 3 utility
		Scalar len(const Vector3& vect);
		Scalar len2(const Vector3& vect);
		Scalar Normalize(const Vector3& vect);
		Vector3 Rotate(const Vector3& vec1, Scalar angle, const Vector3& axis);
		Vector3 VectMult(const Vector3& vec1, const Vector3& vec2);
		Scalar MixMult(const Vector3& vec1, const Vector3& vec2, const Vector3 &vec3);
		Vector3 Rotate(const Vector3& vec1, Scalar angle, const Vector3& axis);
	};

		



		static const Vector3 Zero;// for comparison purposes 
		static const Scalar  Epsilon;
	};





};
