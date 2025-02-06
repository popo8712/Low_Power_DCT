#ifndef QUANTIZE_FIXED_H
#define QUANTIZE_FIXED_H

#include <stdint.h>

#define BLOCK_SIZE 8

void quantize_block_fixed(int16_t block[BLOCK_SIZE][BLOCK_SIZE]);

#endif
