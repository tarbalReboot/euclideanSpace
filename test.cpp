#include <cmath>
#include <iostream>
#include "euclidean.h"

int main()
{
	euclidean::cartesian3 testVector1{3.0, 7.7, 9.1};
	std::cout << "testVector1: " << testVector1[0] << ", " << testVector1[1] << ", " << testVector1[2] << std::endl;
	euclidean::cartesian3 testVector2{1.1, 4.1, 7.4};
	std::cout << "testVector2: " << testVector2[0] << ", " << testVector2[1] << ", " << testVector2[2] << std::endl;

	euclidean vm;

	euclidean::cartesian3 resultAdd = vm.add(testVector1, testVector2);
	std::cout << "add: " << resultAdd[0] << ", " << resultAdd[1] << ", " << resultAdd[2] << std::endl;

	euclidean::cartesian3 resultNorm = vm.normalize(testVector2);
	std::cout << "normalize: " << resultNorm[0] << ", " << resultNorm[1] << ", " << resultNorm[2] << std::endl;

	double dotP = vm.dot(testVector1, testVector2);
	std::cout << "dot: " << dotP << ", " << std::endl;

	euclidean::cartesian3 resultCross = vm.rightCartesianCross(testVector1, testVector2);
	std::cout << "cross: " << resultCross[0] << ", " << resultCross[1] << ", " << resultCross[2] << std::endl;

	euclidean::matrix33 outerP = vm.outerProduct(testVector1, testVector2);
	std::cout << "outer product: " << outerP[0][0] << ", " << outerP[0][1] << ", " <<  outerP[0][2] << std::endl 
		<< "\t\t" << outerP[1][0] << ", " << outerP[1][1] << ", " << outerP[1][2] << std::endl 
		<< "\t\t" << outerP[2][0] << ", " << outerP[2][1] << ", " << outerP[2][2] << std::endl;

	return 0;
}
