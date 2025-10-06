#include "glyph.h"
#include <stdint.h>
void scrave_glyph(uint8_t a2, _Bool *v){
    // glyph(a2: number, v: boolean[]) {
  a2 &= 0xff;
  for (uint8_t i = 0; i < 4; i++) {
    uint8_t a = (a2 >> (i * 2)) & 3;
    uint8_t x = i % 2 == 0 ? 3 : 0;
    uint8_t y = i >= 2 ? 3 : 0;
    // uint8_t put = (a: boolean, b: boolean) => (v[(y + +a) * 5 + x + +b] = 1);
    #define put(a,b) v[(y + a) * 5 + x + b]=1;
    switch (a) {
      case 0: {
        break;
      }
      case 1: {
        put(0, 0);
        put(0, 1);
        put(1, 1);
        break;
      }
      case 2: {
        put(1, 0);
        break;
      }
      case 3: {
        put(0, 0);
        put(1, 0);
        put(1, 1);
      }
    }
  }
  for (uint8_t i = 0; i < 5; i++) {
    if (i == 2) {
      continue;
    }
    v[10 + i] = v[5 + i] && v[15 + i];
    v[i * 5 + 2] = v[i * 5 + 1] && v[i * 5 + 3];
  }
// }
}