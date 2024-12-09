#ifndef DCT_FUNCTIONS_H
#define DCT_FUNCTIONS_H

#include <math.h>

#define N 8

void dct(float input[N][N], float output[N][N]);
void idct(float input[N][N], float output[N][N]);

#endif
