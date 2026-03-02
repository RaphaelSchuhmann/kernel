#include "screen.h"
#include "utils.h"

void exitOS(int status) {
  // Port: 0xf4 (iobase)
  // Value: status (This becomes (status << 1) | 1 in the shell)
  asm volatile("outb %b0, %w1" : : "a"(status), "d"(0xf4));
}

void kmain() {
  init();

  print("Hello World: ");
  char buf[64];
  scan(buf);

  exitOS(0);
}
