#include "msxutil.h"

void game() {
  cls();
  uint8_t x = 15;
  for (;;) {
    put('O', x, 5);
    put('*', rnd() & 31, 23);
    redraw();
    scrollup();
    if (scr(x, 5) == '*') {
      break;
    }
    uint8_t key = inkey();
    if (key == KEY_LEFT) {
      x--;
    } else if (key == KEY_RIGHT) {
      x++;
    }
    wait(1);
  }
}

void main() {
  for (;;) {
    game();
    wait(100);
  }
}
