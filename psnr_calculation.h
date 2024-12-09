#ifndef PSNR_CALCULATION_H
#define PSNR_CALCULATION_H

#include <math.h>
#include <stdio.h>

#define N 8

float calculate_psnr(float original[N][N], float reconstructed[N][N]);

#endif
