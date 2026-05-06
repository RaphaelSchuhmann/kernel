#ifndef SCREEN_H
#define SCREEN_H

#define VGA_MEMORY ((volatile unsigned short *)0xB8000)
#define MAX_STR_LEN 64

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

typedef struct {
  int curCol;
  int curRow;
} Screen;

extern Screen GlobalScreen;

static const char keymap[128] = {
    0,    // 0
    0,    // 1 (ESC)
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
};

void print(const char *message);

void clear();

void clearColInCurrentRow(int col);

void init();

static inline unsigned char inb(unsigned short port);

void getch();

void scan(char *output);

#endif
