#define VGA_MEMORY ((volatile unsigned short *)0xB8000)

void printMessage(const char *msg) {
  int row = 0;
  int col = 0;

  for (int i = 0; msg[i] != 0; i++) {
    if (msg[i] == '\n') {
      col = 0;
      row++;
      continue;
    }
    VGA_MEMORY[row * 80 + col] = (0x0F << 8) | msg[i];
    col++;
  }
}

void kmain() { printMessage("Hello World\nNew Line"); }
