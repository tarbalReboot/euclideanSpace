#include <cmath>
#include <iostream>
#include "euclidean.h"
#include "echelon.h"

int main()
{
	oneForm testVector1{3.0, 7.7, 9.1};
	std::cout << "testVector1: " << testVector1[0] << ", " << testVector1[1] << ", " << testVector1[2] << std::endl;
	oneForm testVector2{1.1, 4.1, 7.4};
	std::cout << "testVector2: " << testVector2[0] << ", " << testVector2[1] << ", " << testVector2[2] << std::endl;

	oneForm resultAdd = add(testVector1, testVector2);
	std::cout << "add: " << resultAdd[0] << ", " << resultAdd[1] << ", " << resultAdd[2] << std::endl;

	oneForm resultNorm = normalize(testVector1);
	std::cout << "normalize: " << resultNorm[0] << ", " << resultNorm[1] << ", " << resultNorm[2] << std::endl;

	double dotP = dot(testVector1, testVector2);
	std::cout << "dot: " << dotP << ", " << std::endl;

	oneForm resultCross = rightCartesianCross(testVector1, testVector2);
	std::cout << "cross: " << resultCross[0] << ", " << resultCross[1] << ", " << resultCross[2] << std::endl;

	twoForm outerP = outerProduct(testVector1, testVector2);
	std::cout << "outer product: " << outerP[0][0] << ", " << outerP[0][1] << ", " <<  outerP[0][2] << std::endl 
		<< "\t\t" << outerP[1][0] << ", " << outerP[1][1] << ", " << outerP[1][2] << std::endl 
		<< "\t\t" << outerP[2][0] << ", " << outerP[2][1] << ", " << outerP[2][2] << std::endl;

	twoForm testInMatrix1;
	testInMatrix1[0][0] = 3; testInMatrix1[1][0] = -7; testInMatrix1[2][0] = -2;
	testInMatrix1[0][1] = -3; testInMatrix1[1][1] = 5; testInMatrix1[2][1] = 1;
	testInMatrix1[0][2] = 6; testInMatrix1[1][2] = -4; testInMatrix1[2][2] = 0;

	twoForm testInMatrix2;
	testInMatrix2[0][0] = 4; testInMatrix2[1][0] = 3; testInMatrix2[2][0] = -5;
	testInMatrix2[0][1] = -4; testInMatrix2[1][1] = -5; testInMatrix2[2][1] = 7;
	testInMatrix2[0][2] = 8; testInMatrix2[1][2] = 6; testInMatrix2[2][2] = -8;

	twoForm testInMatrix3;
	testInMatrix3[0][0] = 2; testInMatrix3[1][0] = -1; testInMatrix3[2][0] = 2;
	testInMatrix3[0][1] = -6; testInMatrix3[1][1] = 0; testInMatrix3[2][1] = -2;
	testInMatrix3[0][2] = 8; testInMatrix3[1][2] = -1; testInMatrix3[2][2] = 5;

	twoForm testInMatrix4;
	testInMatrix4[0][0] = 2; testInMatrix4[1][0] = -2; testInMatrix4[2][0] = 4;
	testInMatrix4[0][1] = 1; testInMatrix4[1][1] = -3; testInMatrix4[2][1] = 1;
	testInMatrix4[0][2] = 3; testInMatrix4[1][2] = 7; testInMatrix4[2][2] = 5;

	twoForm testOutMatrix = echelonU(testInMatrix1);

	std::cout << "3x3 Row Reduced: "<< "\t" << testOutMatrix[0][0] << ", " << testOutMatrix[1][0] << ", " <<  testOutMatrix[2][0] << std::endl 
		<< "\t" << testOutMatrix[0][1] << ", " << testOutMatrix[1][1] << ", " << testOutMatrix[2][1] << std::endl 
		<< "\t" << testOutMatrix[0][2] << ", " << testOutMatrix[1][2] << ", " << testOutMatrix[2][2] << std::endl;

	twoForm testInMatrix5;
	testInMatrix5[0][0] = 1; testInMatrix5[1][0] = -2; testInMatrix5[2][0] = -4; testInMatrix5[3][0] = -3;
	testInMatrix5[0][1] = 2; testInMatrix5[1][1] = -7; testInMatrix5[2][1] = -7; testInMatrix5[3][1] = -6;
	testInMatrix5[0][2] = -1; testInMatrix5[1][2] = 2; testInMatrix5[2][2] = 6; testInMatrix5[3][2] = 4;
	testInMatrix5[0][3] = -4; testInMatrix5[1][3] = -1; testInMatrix5[2][3] = 9; testInMatrix5[3][3] = 8;
	
	twoForm testInMatrix6;
	testInMatrix6[0][0] = 0; testInMatrix6[1][0] = 3; testInMatrix6[2][0] = 4; testInMatrix6[3][0] = 0;
	testInMatrix6[0][1] = -3; testInMatrix6[1][1] = -6; testInMatrix6[2][1] = -7; testInMatrix6[3][1] = 2;
	testInMatrix6[0][2] = 3; testInMatrix6[1][2] = 3; testInMatrix6[2][2] = 0; testInMatrix6[3][2] = -4;
	testInMatrix6[0][3] = -5; testInMatrix6[1][3] = -3; testInMatrix6[2][3] = 2; testInMatrix6[3][3] = 9;

	std::cout << "4x4 In: "<< "\t" << testInMatrix6[0][0] << ", " << testInMatrix6[1][0] << ", " <<  testInMatrix6[2][0] << ", " << testInMatrix5[3][0] << std::endl 
		<< "\t" << testInMatrix6[0][1] << ", " << testInMatrix6[1][1] << ", " << testInMatrix6[2][1] << ", " << testInMatrix6[3][1] << std::endl 
		<< "\t" << testInMatrix6[0][2] << ", " << testInMatrix6[1][2] << ", " << testInMatrix6[2][2] << ", " << testInMatrix6[3][2] << std::endl
		<< "\t" << testInMatrix6[0][3] << ", " << testInMatrix6[1][3] << ", " << testInMatrix6[2][3] << ", " << testInMatrix6[3][3] << std::endl;
		
	twoForm testOutMatrix4 = echelonU(testInMatrix6);

	std::cout << "4x4 Row Reduced: "<< "\t" << testOutMatrix4[0][0] << ", " << testOutMatrix4[1][0] << ", " <<  testOutMatrix4[2][0] << ", " << testOutMatrix4[3][0] << std::endl 
		<< "\t" << testOutMatrix4[0][1] << ", " << testOutMatrix4[1][1] << ", " << testOutMatrix4[2][1] << ", " << testOutMatrix4[3][1] << std::endl 
		<< "\t" << testOutMatrix4[0][2] << ", " << testOutMatrix4[1][2] << ", " << testOutMatrix4[2][2] << ", " << testOutMatrix4[3][2] << std::endl
		<< "\t" << testOutMatrix4[0][3] << ", " << testOutMatrix4[1][3] << ", " << testOutMatrix4[2][3] << ", " << testOutMatrix4[3][3] << std::endl;

	return 0;
}
