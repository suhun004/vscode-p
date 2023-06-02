#include <stdio.h>
#include <stdlib.h>
#define n 10

int main()
{
  int* a = (int*) malloc(sizeof(char) * n * 4);
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
    printf("%d ", a[i]);
  }
  
  printf("\n%lu\n", sizeof(*a));
  free(a);

  return 0;
}

int alpha_f(int a) {
  return a;
}