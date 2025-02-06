#include "dct_fixed.h"
#include <string.h>
#include <math.h>

static int16_t cos_table[BLOCK_SIZE][BLOCK_SIZE];

void init_dct_lut() {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            cos_table[i][j] = (int16_t)(cos((2 * i + 1) * j * M_PI / 16) * FIXED_POINT_SCALE);
        }
    }
}

void apply_dct_fixed(int16_t block[BLOCK_SIZE][BLOCK_SIZE]) {
    int32_t temp[BLOCK_SIZE][BLOCK_SIZE] = {0};

    for (int u = 0; u < BLOCK_SIZE; u++) {
        for (int v = 0; v < BLOCK_SIZE; v++) {
            int32_t sum = 0;
            for (int x = 0; x < BLOCK_SIZE; x++) {
                for (int y = 0; y < BLOCK_SIZE; y++) {
                    sum += block[x][y] * cos_table[x][u] * cos_table[y][v];
                }
            }
            temp[u][v] = (sum / (FIXED_POINT_SCALE * FIXED_POINT_SCALE));  // 還原小數
        }
    }
    memcpy(block, temp, sizeof(temp));
}
