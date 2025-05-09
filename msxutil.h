#include <msx/gfx.h>

#define MSX_JIFFY 0xfc9e

#define VRAM_SCREEN  0x1800
#define WIDTH 32
#define HEIGHT 24
#define SPACE 0x20

void wait_vsync(uint16_t count) {
  uint16_t *interval_timer = (uint16_t*)MSX_JIFFY;
  *interval_timer = 0;
  while (*interval_timer < count);
}

// vvram
static uint8_t vvram[WIDTH * HEIGHT];

void vvram_clear() {
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    vvram[i] = 0;
  }
}
void vvram_put(uint8_t ch, uint8_t x, uint8_t y) {
  vvram[y * WIDTH + x] = ch;
}
void vvram_redraw() {
  vwrite(vvram, VRAM_SCREEN, WIDTH * HEIGHT);
}
void vvram_scrollup() { // todo: use memcopy
  for (int i = 0; i < WIDTH * (HEIGHT - 1); i++) {
    vvram[i] = vvram[i + WIDTH];
  }
  for (int i = 0; i < WIDTH; i++) {
    vvram[i + WIDTH * (HEIGHT - 1)] = SPACE;
  }
}
uint8_t vvram_get(uint8_t x, uint8_t y) {
  return vvram[y * WIDTH + x];
}

// util
uint8_t rnd_seed = 0;
uint8_t rnd() {
  rnd_seed = rnd_seed * 5 + 1;
  return rnd_seed;
}

#define KEY_LEFT 7
#define KEY_RIGHT 3
// a: 1=up, 2=right up, 3=right, 4=right down, 5=down, 6=left down, 7=left, 8=left up
uint8_t inkey() __naked {
#asm
  ld a, 0
  call 0x00D5
  ld h, 0
  ld l, a
  ret
#endasm
}

#define cls vvram_clear
#define put vvram_put
#define scr vvram_get
#define scrollup vvram_scrollup
#define redraw vvram_redraw
#define wait wait_vsync
