// VCTR.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector3.h"
#include "Vector3Op.h"
#include <iostream>
using namespace VectMath;
using namespace std;
int main()
{//minimal output capabilities
	Vector3 a;
	Vector3 b;
	std::cin >> a.X>>a.Y>>a.Z;
	std::cin >> b.X>>b.Y>>b.Z;
	std::cout << len(a) << len2(b);
	std::cout << len(a/2)<<len(b/2);
	
	return 0;
}

