#include <stdio.h>
#define MAX 9

void fn_print_num(int);

int main() {
  printf("Hello World!\n");
  for (int i = 1; i < MAX + 1; i++) {
  fn_print_num(i);
   if (i == MAX) {
   }
   else {
      printf(" ");
   }
  }
  return 0;
}

void fn_print_num(int a) {
  printf("%d", a);
}