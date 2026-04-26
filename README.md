Euclidean 0.1.0

Euclidean, as in Euclidean space, is designed to assist in development of 3-dimensional space (and potentially relativistic curved space in the future) software in C++. Assignment is straightforward. Each element of each matrix or vector can be directly manipulated. Perhaps the best feature is methods being able to have 2x2, 3x3, and 4x4 matrix and 2D, 3D, and 4D vector return values. Since the focus is Euclidean space, the initial (0.1.0) release is limited to a maximum of 4 dimensions, so manually allocating memory with malloc() is superflous. 

The initial (0.1.0) release contains typedefs of 2x2, 3x3, and 4x4 matrices, along with 2D, 3D, and 4D vectors. Addition, dot (inner) scalar product, right cartesian cross product (3D only), and normalization of vectors are included in one "drop-in" header file. I hesitate to promise any additions in particular for future releases, but let's just say I'm ambitious, and I can't seem to get the functionality I want from alternative linear algebra packages. Included is a little test program to show you how the current existing function calls work.

GNU Public License (copyleft). Any redistribution of this software in any form with any modifications must retain this license agreement. 

John E. Petersen III, 2026
