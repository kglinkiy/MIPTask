#include "Vector3Op.h"



namespace VectMath
{
	void Clamp(Vector3& vect, Scalar length)
	{
		Scalar vecLength = len2(vect);

		// fixit: может == ?
		if (vecLength = length * length)
		{
			return;
		}

		vect *= length / sqrt(vecLength);
	}

	void Normalize_s(Vector3& vect)
	{
		Scalar vecLength = len2(vect);

		if (vecLength == 0)
		{
			return;
		}

		vect /= sqrt(vecLength);
	}

	void SetLength_s(Vector3& vect, Scalar length)
	{
		Scalar vecLength = len2(vect);

		if (vecLength == 0)
		{
			return;
		}

		vect *= length / sqrt(vecLength);
	}

	inline Scalar   GetAngle(Vector3 vec1, Vector3 vec2)
	{
		if (vec1 == vec2)
		{
			return 0.0f;
		}

		Normalize_s(vec1);
		Normalize_s(vec2);

		Scalar dot = ScalMult(vec1, vec2) / (len(vec1) * len(vec2));

		dot = dot > 1.0f ? 1.0f : (dot < -1.0f ? -1.0f : dot);

		return std::acos(dot);
	}

	Vector3 ToNormalized_s(const Vector3& vect)
	{
		Scalar vecLength = len2(vect);

		// лучше сравнивать с Epsilon, а не с нулем
		if (vecLength == 0)
		{
			return vect;
		}

		vecLength = sqrt(vecLength);

		return Vector3(vect.X / vecLength, vect.Y / vecLength, vect.Z / vecLength);
	}
	Vector3 Rotate( Vector3& vec1, Scalar angle,  Vector3& axis){
		       //it isn't stealing if its under gpl or educational
		
			Vector3 axisNorm = axis;
			Normalize_s(axisNorm);
			Scalar cosA = std::cos(angle);
			Scalar sinA = std::sin(angle);
			Vector3 self = *this;
			Vector3 a = self - axisNorm*ScalMult(axisNorm,self);
			Vector3 b = VectMult(a,axisNorm);
			Vector3 delta = a * cosA + b * sinA - a;
			self += delta;
			*this = self;
			return *this;
			
	
	
	};


}
