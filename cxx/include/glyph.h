#pragma once
#include <stdbool.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void scrave_glyph(uint8_t a, _Bool *v);
extern const char scrave_SBOX[256];
extern const char scrave_SBOX_INV[256];
#ifdef __cplusplus
}
#endif
