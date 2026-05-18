#ifndef SCREEN_H
#define SCREEN_H

#define VGA_MEMORY ((volatile unsigned short *)0xB8000)
#define MAX_STR_LEN 128

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

#define LEFT_SHIFT_MAKE 0x2A
#define LEFT_SHIFT_BREAK 0xAA
#define RIGHT_SHIFT_MAKE 0x36
#define RIGHT_SHIFT_BREAK 0xB6

static int shiftPressed = 0;

typedef struct {
  int curCol;
  int curRow;
} Screen;

extern Screen GlobalScreen;

static const char KeymapLowercase[58] = {
    0,   27,  '1',  '2',  '3',  '4', '5', '6',  '7', '8', '9', '0',
    '-', '=', '\b', '\t', 'q',  'w', 'e', 'r',  't', 'y', 'u', 'i',
    'o', 'p', '[',  ']',  '\n', 0,   'a', 's',  'd', 'f', 'g', 'h',
    'j', 'k', 'l',  ';',  '\'', '`', 0,   '\\', 'z', 'x', 'c', 'v',
    'b', 'n', 'm',  ',',  '.',  '/', 0,   '*',  0,   ' '};

static const char KeymapUppercase[58] = {
    0,   27,  '!',  '@',  '#',  '$', '%', '^', '&', '*', '(', ')',
    '_', '+', '\b', '\t', 'Q',  'W', 'E', 'R', 'T', 'Y', 'U', 'I',
    'O', 'P', '{',  '}',  '\n', 0,   'A', 'S', 'D', 'F', 'G', 'H',
    'J', 'K', 'L',  ':',  '"',  '~', 0,   '|', 'Z', 'X', 'C', 'V',
    'B', 'N', 'M',  '<',  '>',  '?', 0,   '*', 0,   ' '};

void print(const char *message);

void clear();

void clearColInCurrentRow(int col);

void init();

static inline unsigned char inb(unsigned short port);

char getch();

void scan(char *output);

int getPrevRowUsedColumns(char *str);

void flushKeyboard();

#endif
