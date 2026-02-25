#include "screen.h"

void kmain() {
  init();

  print("Enter something\n");

  char buffer[64];
  scan(buffer);
  print(buffer);
}
