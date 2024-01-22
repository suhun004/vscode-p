#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int longrand();
static double data;

int main()
{ 
  longrand();
  longrand();
  longrand();
  return 0;
}

int longrand() {
  static int sx = 10;
  printf("%d\n", sx);
  sx += 5;
}