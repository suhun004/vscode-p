#include <stdio.h>

int main() {
  printf("Hello World!\n");
  for (int i = 0; i < 10; i++) {
   if (i == 9) {
    printf("%d\n", i);
   }
   else {
      printf("%d ", i);
   }
  }
  return 0;
}