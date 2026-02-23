#include "screen.h"

Screen GlobalScreen;

void init() {
  GlobalScreen.curCol = 0;
  GlobalScreen.curRow = 0;
  clear();
}

void print(const char *message) {
  if (GlobalScreen.curRow > 0)
    GlobalScreen.curRow++; // Increment to a new line

  GlobalScreen.curCol = 0; // Reset current column

  for (int i = 0; message[i] != 0; i++) {
    if (message[i] == '\n') {
      GlobalScreen.curCol = 0;
      GlobalScreen.curRow++;
      continue;
    }
    VGA_MEMORY[GlobalScreen.curRow * 80 + GlobalScreen.curCol] =
        (0x0F << 8) | message[i];
    GlobalScreen.curCol++;
  }

  return;
}

void clear() {
  const char *msg = " ";
  for (int row = 0; row < 25; row++) {
    for (int col = 0; col < 80; col++) {
      VGA_MEMORY[row * 80 + col] = (0x0F << 8) | msg[0];
    }
  }
}
