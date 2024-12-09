#ifndef QUANTIZATION_H
#define QUANTIZATION_H

#define N 8

void quantize(float dct_coeff[N][N], int quant_table[N][N], int output[N][N]);
void inverse_quantize(int quantized[N][N], int quant_table[N][N], float output[N][N]);

#endif
