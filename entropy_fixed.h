#ifndef ENTROPY_FIXED_H
#define ENTROPY_FIXED_H

#include <stdint.h>

#define BLOCK_SIZE 8
#define MAX_HUFFMAN_NODES 256

typedef struct {
    int16_t value;
    int16_t count;
} RLECode;

typedef struct HuffmanNode {
    int16_t value;
    int frequency;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

void rle_encode_fixed(int16_t block[BLOCK_SIZE][BLOCK_SIZE], RLECode output[], int *size);
void huffman_encode_fixed(RLECode codes[], int code_count, uint8_t output[], int *output_size);

#endif
