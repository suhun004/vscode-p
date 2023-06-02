#include <stdio.h>
#include <string.h>


void ch_f()
{
  char a[] = "";
  char b[] = "";
  printf("역순으로 출력받을 문자열을 입력하세요\n");
  scanf("%s", a);
  int n = strlen(a) + 1;
  for(int i = 0; i < n; i++) {
    printf("%c", a[n - i - 2]);
  }
  printf("\n");
}