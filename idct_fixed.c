#include "idct_fixed.h"
#include <string.h>

extern int16_t cos_table[BLOCK_SIZE][BLOCK_SIZE];

void apply_idct_fixed(int16_t block[BLOCK_SIZE][BLOCK_SIZE]) {
    int32_t temp[BLOCK_SIZE][BLOCK_SIZE] = {0};

    for (int x = 0; x < BLOCK_SIZE; x++) {
        for (int y = 0; y < BLOCK_SIZE; y++) {
            int32_t sum = 0;
            for (int u = 0; u < BLOCK_SIZE; u++) {
                for (int v = 0; v < BLOCK_SIZE; v++) {
                    sum += cos_table[u][x] * cos_table[v][y] * block[u][v];
                }
            }
            temp[x][y] = sum / (FIXED_POINT_SCALE * FIXED_POINT_SCALE);
        }
    }
    memcpy(block, temp, sizeof(temp));
}
