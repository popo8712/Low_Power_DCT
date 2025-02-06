#include "entropy_fixed.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_HUFFMAN_NODES 256  // 霍夫曼樹最多 256 個節點

// **游程編碼（RLE, Run-Length Encoding）**
void rle_encode_fixed(int16_t block[BLOCK_SIZE][BLOCK_SIZE], RLECode output[], int *size) {
    int index = 0;
    int prev = block[0][0];
    int count = 1;

    for (int i = 1; i < BLOCK_SIZE * BLOCK_SIZE; i++) {
        int row = i / BLOCK_SIZE;
        int col = i % BLOCK_SIZE;
        int16_t value = block[row][col];

        if (value == prev) {
            count++;
        } else {
            output[index].value = prev;
            output[index].count = count;
            index++;
            prev = value;
            count = 1;
        }
    }

    output[index].value = prev;
    output[index].count = count;
    *size = index + 1;
}

// **建立霍夫曼樹**
static HuffmanNode* build_huffman_tree(int freq_table[]) {
    HuffmanNode *nodes[MAX_HUFFMAN_NODES];
    int node_count = 0;

    // 創建葉節點
    for (int i = 0; i < MAX_HUFFMAN_NODES; i++) {
        if (freq_table[i] > 0) {
            nodes[node_count] = (HuffmanNode *)malloc(sizeof(HuffmanNode));
            nodes[node_count]->value = i - 128;  // 調整範圍
            nodes[node_count]->frequency = freq_table[i];
            nodes[node_count]->left = NULL;
            nodes[node_count]->right = NULL;
            node_count++;
        }
    }

    // 建立 Huffman Tree
    while (node_count > 1) {
        // 找到兩個最小頻率的節點
        int min1 = 0, min2 = 1;
        for (int i = 2; i < node_count; i++) {
            if (nodes[i]->frequency < nodes[min1]->frequency) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->frequency < nodes[min2]->frequency) {
                min2 = i;
            }
        }

        // 建立新節點
        HuffmanNode *parent = (HuffmanNode *)malloc(sizeof(HuffmanNode));
        parent->value = -1;
        parent->frequency = nodes[min1]->frequency + nodes[min2]->frequency;
        parent->left = nodes[min1];
        parent->right = nodes[min2];

        // 重新整理樹
        nodes[min1] = parent;
        nodes[min2] = nodes[node_count - 1];
        node_count--;
    }

    return nodes[0];  // 返回 Huffman Tree 根節點
}

// **遞迴生成霍夫曼編碼**
static void generate_huffman_codes(HuffmanNode *root, char *code, int depth, char *codes[]) {
    if (!root) return;

    if (!root->left && !root->right) {
        code[depth] = '\0';
        codes[root->value + 128] = strdup(code);
        return;
    }

    code[depth] = '0';
    generate_huffman_codes(root->left, code, depth + 1, codes);
    
    code[depth] = '1';
    generate_huffman_codes(root->right, code, depth + 1, codes);
}

// **霍夫曼編碼**
void huffman_encode_fixed(RLECode codes[], int code_count, uint8_t output[], int *output_size) {
    int freq_table[MAX_HUFFMAN_NODES] = {0};

    // **統計頻率**
    for (int i = 0; i < code_count; i++) {
        int index = codes[i].value + 128;
        freq_table[index]++;
    }

    // **建立霍夫曼樹**
    HuffmanNode *root = build_huffman_tree(freq_table);

    // **生成霍夫曼編碼表**
    char *huffman_codes[MAX_HUFFMAN_NODES] = {NULL};
    char code[MAX_HUFFMAN_NODES] = {0};
    generate_huffman_codes(root, code, 0, huffman_codes);

    // **壓縮數據**
    int bit_position = 0;
    int byte_index = 0;
    output[byte_index] = 0;

    for (int i = 0; i < code_count; i++) {
        char *symbol_code = huffman_codes[codes[i].value + 128];

        for (int j = 0; symbol_code[j] != '\0'; j++) {
            if (symbol_code[j] == '1') {
                output[byte_index] |= (1 << (7 - bit_position));
            }
            bit_position++;

            if (bit_position == 8) {
                bit_position = 0;
                byte_index++;
                output[byte_index] = 0;
            }
        }
    }

    *output_size = byte_index + 1;

    // **釋放記憶體**
    for (int i = 0; i < MAX_HUFFMAN_NODES; i++) {
        if (huffman_codes[i]) free(huffman_codes[i]);
    }
}

// **釋放霍夫曼樹記憶體**
static void free_huffman_tree(HuffmanNode *root) {
    if (!root) return;
    free_huffman_tree(root->left);
    free_huffman_tree(root->right);
    free(root);
}
