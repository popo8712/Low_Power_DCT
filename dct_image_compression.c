#include <math.h>
#include <stdio.h>

#define N 8  // 8x8 區塊

void dct(float input[N][N], float output[N][N]) {
    float alpha, beta, sum;
    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            alpha = (u == 0) ? sqrt(1.0 / N) : sqrt(2.0 / N);
            beta = (v == 0) ? sqrt(1.0 / N) : sqrt(2.0 / N);
            sum = 0.0;

            for (int x = 0; x < N; x++) {
                for (int y = 0; y < N; y++) {
                    sum += input[x][y] * cos((2 * x + 1) * u * M_PI / (2 * N)) *
                           cos((2 * y + 1) * v * M_PI / (2 * N));
                }
            }
            output[u][v] = alpha * beta * sum;
        }
    }
}
