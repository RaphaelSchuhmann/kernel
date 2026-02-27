#include "screen.h"
#include "utils.h"

void kmain() {
  init();

  print("Enter something\n");

  char itoaResult[32];
  itoa(255, itoaResult, 2);
  print(itoaResult);
}
