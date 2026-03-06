#include "screen.h"

Screen GlobalScreen;

void init() {
  GlobalScreen.curCol = 0;
  GlobalScreen.curRow = 0;
  clear();
}

void print(const char *message) {
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
}

void clearColInCurrentRow(int col) {
  if (col < 0)
    return;
  VGA_MEMORY[GlobalScreen.curRow * 80 + col] = (0x0F << 8) | ' ';
}

void clear() {
  for (int row = 0; row < 25; row++) {
    for (int col = 0; col < 80; col++) {
      VGA_MEMORY[row * 80 + col] = (0x0F << 8) | ' ';
    }
  }
}

static inline unsigned char inb(unsigned short port) {
  unsigned char ret;
  asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
  return ret;
}

void getch() {
  // Wait for key
  while (!(inb(0x64) & 1)) {
  }

  unsigned short scancode = inb(0x60);

  // Ignore extended keys for now
  if (scancode == 0xE0)
    return;

  // Ignore releases
  if (scancode & 0x80)
    return;

  unsigned short key = scancode & 0x7F;

  char keyChar = keymap[key];

  if (keyChar != 0) {
    char str[2] = {keyChar, '\0'};
    print(str);
  }
}

void scan(char *output) {
  int index = 0;

  while (1) {
    // Wait for key
    while (!(inb(0x64) & 1)) {
    }

    unsigned short scancode = inb(0x60);

    if (scancode == 0xE0)
      continue;

    // Ignore releases
    if (scancode & 0x80)
      continue;

    unsigned short key = scancode & 0x7F;

    char keyChar = keymap[key];

    if (keyChar != 0) {
      if (keyChar == '\b' && index >= 0) { // Backspace
        if (index > 0 && GlobalScreen.curCol > 0) {
          index--;
          GlobalScreen.curCol--;
        }

        clearColInCurrentRow(GlobalScreen.curCol);
      } else if (keyChar == '\n') { // Nullterminate string and return
        print("\n");
        output[index] = '\0';
        break;
      } else if (index < MAX_STR_LEN - 1 && keyChar != '\b') {
        char tempStr[2] = {keyChar, '\0'};
        print(tempStr);

        output[index] = keyChar;
        index++;
      }
    }
  }

  return;
}
