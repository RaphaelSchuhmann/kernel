#define VGA_MEMORY ((volatile unsigned short *)0xB8000)

void printMessage(const char *msg) {
  for (int i = 0; msg[i] != 0; i++) {
    VGA_MEMORY[i] = (0x0F << 8) | msg[i];
  }
}

void kmain() { printMessage("Hello World"); }
