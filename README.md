# Embedded Vision with Low-Power DCT on ARM（基於 ARM 的嵌入式低功耗 DCT 影像處理）

More implementation records-->https://hackmd.io/@popo8712/HkAb6q5eJx



## Overview
This project implements a Discrete Cosine Transform (DCT)-based image compression algorithm using the C programming language on an ARM Cortex-A platform (Raspberry Pi 3 Model B). The code includes DCT computation, quantization, and PSNR calculation.

## Files
1. `dct_image_compression.c` - Main program.
2. `dct_functions.h` - DCT and IDCT implementations.
3. `quantization.h` - Quantization and dequantization functions.
4. `psnr_calculation.h` - PSNR calculation.
5. `uart_communication.c` - UART simulation for data transfer.
6. `test_data_generator.py` - Generates test data.
7. `README.md` - Project documentation.

## How to Run
1. Compile the program:
   ```
   gcc dct_image_compression.c -o dct_image_compression -lm
   ```
2. Execute:
   ```
   ./dct_image_compression
   ```
3. Use Python to generate test data:
   ```
   python3 test_data_generator.py
   ```

## Requirements
- GCC
- Python 3.x
