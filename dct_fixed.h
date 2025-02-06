#ifndef DCT_FIXED_H
#define DCT_FIXED_H

#include <stdint.h>

#define FIXED_POINT_SCALE 1024  // 10-bit 精度（2^10）
#define BLOCK_SIZE 8

void init_dct_lut();
void apply_dct_fixed(int16_t block[BLOCK_SIZE][BLOCK_SIZE]);

#endif
