#ifndef SCREEN_H
#define SCREEN_H

#define VGA_MEMORY ((volatile unsigned short *)0xB8000)

typedef struct {
  int curCol;
  int curRow;
} Screen;

extern Screen GlobalScreen;

void print(const char *message);

void clear();

void init();

#endif
