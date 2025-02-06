#ifndef IDCT_FIXED_H
#define IDCT_FIXED_H

#include <stdint.h>

#define BLOCK_SIZE 8

void apply_idct_fixed(int16_t block[BLOCK_SIZE][BLOCK_SIZE]);

#endif
