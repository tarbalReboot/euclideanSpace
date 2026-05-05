#ifndef ECHELON_HPP
#define ECHELON_HPP
#include "euclidean.h"

//Swaps rows during echelon reduction
twoForm rowSwap(twoForm inMat, int index1, int index2)
{
    unsigned long int mSize = inMat.size();
    twoForm tempMatrix = inMat;
    for (int m = 0; m <= mSize - 1 - index1; m++)
        {
            inMat[index1 + m][index2] = tempMatrix[index1 + m][index1];
            inMat[index1 + m][index1] = tempMatrix[index1 + m][index2];
        }
    return inMat;
}

//Echelon row reduction in R4 
//(R3 and R2 are handled automatically by leaving remaining R4 elements empty)
twoForm echelonU(twoForm inMatrix)
{
    unsigned long int mSize = inMatrix.size();
    long double factor;
    for(int i = 0; i <= 2; i++)
    {
        for (int j = 1; j <= mSize - 1; j++)
        {
            factor = -inMatrix[i][j] / inMatrix[i][i];
            if(inMatrix[i][i] != 0)
            {
                for(int k = 0; k <= mSize - 1; k++)
                {
                    if(i == 1 && (j == 1 || k == 0))
                        continue;
                    if(i == 2 && (j == 1 || j == 2 || k == 0 || k == 1))
                        continue;
                    if(inMatrix[i][i] != 0)
                    {
                        if(factor != 0)
                        {
                            inMatrix[k][j] = (factor * inMatrix[k][i]) + inMatrix[k][j];
                        }
        	    }
                }
            }
            else 
            {
                if (i <= 2 && inMatrix[i][i + 1] != 0)
                        inMatrix = rowSwap(inMatrix, i, i+1);
            	else
        	{
                    if(i <= 1 && inMatrix[i][i+2] != 0)
                        rowSwap(inMatrix, i, i+2);
                    else
                    {
                        if (i == 0 && inMatrix[i][i+3] != 0)
                            rowSwap(inMatrix, i, i+3);
                    }
                }
        	j--;
                continue;
            }
    }
    }
    return inMatrix;
}

#endif // ECHELON_HPP
