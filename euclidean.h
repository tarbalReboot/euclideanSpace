#ifndef EUCLIDEAN_H
#define EUCLIDEAN_H
#include <cmath>
#include <iostream>
#include <array>

/* Many linear algebra packages exist, but I have found them
 * all to have some limitation or another in either arithmetic
 * operations or in assignment. The goal of euclidean.h is to
 * alleviate both of these concerns. It should be noted that
 * capacity need not be explicitly assigned, as it will
 * automatically adjust to approximate the size < R4. */

typedef std::array<std::array <long double, 4>, 4> twoForm;
    
typedef std::array<long double, 4> oneForm;


// adds two vectors of the same length -- will not add and will return only the first vector, if the two vectors have different dimensions. Flip sign of vec2 to subtract.
oneForm add(oneForm vec1, oneForm vec2)
{
    oneForm sum;
    if(vec1.size() != vec2.size())
    {
        std::cerr << "The two provided vectors are of different dimensions and cannot be added! See std::vector<double> add(...) method in vectorMath.h" << std::endl;
        return vec1;
    }
    else
    {
        for (int i=0; i < (int)vec1.size(); i++)
        {
            sum[i] = vec1[i] + vec2[i];
        }
    }
    return sum;
}

// the scalar dot product requires two vectors of the same dimension as input.
double dot(oneForm vec1, oneForm vec2)
{
    double dotScalar;

    if(vec1.size() != vec2.size())
    {
        std::cerr << "The two provided vectors are of different dimensions and cannot be added! See std::vector<double> add(...) method in vectorMath.h" << std::endl;
        return 0;
    }
    else
    {
        for (int i=0; i < (int)vec1.size(); i++)
        {
            dotScalar += vec1[i] * vec2[i];
        }
    }
    return dotScalar;
}

// vector outer products do not require equal dimensionality
twoForm outerProduct(oneForm columnVector, oneForm rowVector)
{
    twoForm rProduct;
    for(int i=0; i< (int)columnVector.size(); i++)
    {
        for(int j=0; j< (int)rowVector.size(); j++)
        {
            rProduct[i][j] = columnVector[i] * rowVector[j];
        }
    }
    return rProduct;
}

// the cross product in a right-handed system requires two three-dimensional vectors.
// If vector1 and vector2 are not both three-dimensional, the method returns vector1,
// rather than taking an impossible cross product. These cross products are right-handed.
oneForm rightCartesianCross(oneForm vec1, oneForm vec2)
{
    if(vec1.size() != 3 || vec2.size() != 3)
        return vec1;
    else
    {
        oneForm rProduct;
        rProduct[0] = vec1[1]*vec2[2] - vec1[2]*vec2[1];
        rProduct[1] = -(vec1[0]*vec2[2] - vec1[2]*vec2[0]);
        rProduct[2] = vec1[0]*vec2[1] - vec1[1]*vec2[0];
        return rProduct;
    }
}

// calculates a unit vector of the given vector of unit length one
oneForm normalize(oneForm givenVector)
{
    double sumOfSquares;
    for(int i=0; i< (int)givenVector.size(); i++)
    {
        sumOfSquares += givenVector[i] * givenVector[i];
        givenVector[i] = givenVector[i] / sumOfSquares;
    }
    return givenVector;
}

#endif // EUCLIDEAN_H
