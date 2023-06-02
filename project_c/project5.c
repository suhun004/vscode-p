#include <stdio.h>
#include <stdarg.h>

int arvg(int, ...);

int main()
{
  printf("%d", arvg(5, 1, 1, 1, 1, 1, 1, 1, 1, 1));

  return 0;
}

int arvg(int num, ...) {
  int sum;
  va_list ap;
  va_start(ap, num);
  sum += va_arg(ap, int);
  sum += va_arg(ap, int);
  sum += va_arg(ap, int);
  sum += va_arg(ap, int);
  sum += va_arg(ap, int);
  sum += va_arg(ap, int);
  sum += va_arg(ap, int);
  
  return sum;
}