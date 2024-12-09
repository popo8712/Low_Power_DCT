#include <stdio.h>
#include "uart_communication.h"

void send_data_over_uart(int data[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", data[i][j]); // 模擬 UART 傳輸
        }
        printf("\n");
    }
}
