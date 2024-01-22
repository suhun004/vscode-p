#include <stdio.h>
 
#define  MAX_LEN  80
 
int main(void)
{
  FILE *stream;
  long l;
  float fp;
  char s[MAX_LEN + 1];
  char c;

  stream = fopen("myfile", "r");

  fscanf(stream, "%s\n", &s [0]);
  fscanf(stream, "%ld\n", &l);
  fscanf(stream, "%c\n", &c);
  fscanf(stream, "%f\n", &fp);

  printf("string = %s\n", s);
  printf("long double = %ld\n", l);
  printf("char = %c\n", c);
  printf("float = %f\n", fp);
}