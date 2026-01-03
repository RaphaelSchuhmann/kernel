// TODO: Implement clear screen function
// TODO: Implement scan function
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

static inline unsigned char inb(unsigned short port) {
  unsigned char ret;
  asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
  return ret;
}

static const char keymap[128] = {
    0,    // 0
    0,    // 1 (ESC if you want)
    '1',  // 2
    '2',  // 3
    '3',  // 4
    '4',  // 5
    '5',  // 6
    '6',  // 7
    '7',  // 8
    '8',  // 9
    '9',  // 10
    '0',  // 11
    0,    // 12 (-)
    0,    // 13 (=)
    '\b', // 14 Backspace
    '\t', // 15 Tab
    'q',  // 16
    'w',  // 17
    'e',  // 18
    'r',  // 19
    't',  // 20
    'y',  // 21
    'u',  // 22
    'i',  // 23
    'o',  // 24
    'p',  // 25
    0,    // 26 ([)
    0,    // 27 (])
    '\n', // 28 Enter
    0,    // 29 Ctrl
    'a',  // 30
    's',  // 31
    'd',  // 32
    'f',  // 33
    'g',  // 34
    'h',  // 35
    'j',  // 36
    'k',  // 37
    'l',  // 38
    0,    // 39 (;)
    0,    // 40 (')
    0,    // 41 (`~)
    0,    // 42 Left Shift
    '\\', // 43 (\)
    'z',  // 44
    'x',  // 45
    'c',  // 46
    'v',  // 47
    'b',  // 48
    'n',  // 49
    'm',  // 50
    ',',  // 51
    '.',  // 52
    '/',  // 53
    0,    // 54 Right Shift
    '*',  // 55 (numpad *)
    0,    // 56 Alt
    ' ',  // 57 Space
    0,    // 58 Caps Lock
          // etc...
};

void getch() {
  while (!(inb(0x64) & 1)) {
    // Wait for key
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
    printMessage(str);
  }
}

void kmain() {
  printMessage("Hello World\n");
  getch();
}
