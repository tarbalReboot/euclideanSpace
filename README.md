Euclidean 0.2.0

Euclidean, as in Euclidean space, is designed to assist in development of R2, R3, and R4 software in C++. Assignment is straightforward. Each element of each matrix or vector can be directly manipulated. Perhaps the best feature is methods being able to have 2x2, 3x3, and 4x4 two-form tensor (matrix) and 2D, 3D, and 4D one-form tensor (vector) return values. Since the focus is Euclidean space, this (0.2.0) release is limited to a maximum of 4 dimensions, i.e., convex manifolds, but manually allocating memory for 16 long doubles at a time with malloc() may be superflous. 

This (0.2.0) release contains typedefs 4x4 matrices, 4D vectors, and their 2D and 3D counterparts -- all in two typedefs. Addition, dot (inner) scalar product, right cartesian cross product (3D only), and normalization of vectors are included in one "drop-in" header file. This is the second release which includes a second "drop-in" header file, allowing for R2, R3, and R4 Echelon row reduction. Included is a little test program to show you how the current existing function calls work.

GNU Public License (copyleft). Any redistribution of this software in any form with any modifications must retain this license agreement. 

John E. Petersen III, 2026
jepetersen@utexas.edu
