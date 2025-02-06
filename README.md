# Embedded Vision with Low-Power DCT on ARM（基於 ARM 的嵌入式低功耗 DCT 影像處理）


## Overview
This project implements a Discrete Cosine Transform (DCT)-based image compression algorithm using the C programming language on an ARM Cortex-A platform (Raspberry Pi 3 Model B). The code includes DCT computation, quantization, and PSNR calculation.

## Files
/dct_project/src

/dct_fixed.h            # DCT 轉換

/dct_fixed.c            # DCT 轉換

/idct_fixed.h           # IDCT 轉換

/idct_fixed.c           # IDCT 轉換

/quantize_fixed.h       # 量化處理

/quantize_fixed.c       # 量化處理

/entropy_fixed.h        # 熵編碼
/entropy_fixed.c        # 熵編碼
/image_prep.h           # 影像預處理
/image_prep.c           # 影像預處理（YCbCr 轉換）
/main.c
/dct_project/test
/test_dct.c
/test_idct.c
/test_quantize.c
/test_entropy.c
/dct_project/data
/raw/                   # 原始測試影像
/processed/             # 處理後的影像
/dct_project/Makefile   # 編譯設定檔
