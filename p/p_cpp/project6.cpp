#include <iostream>

int f(int);

int main() {
  int a;
  printf("이것은 팩토리알을 나타내는 프로그램입니다.\n");
  printf("숫자를 입력하세요 : ");
  scanf("%d", &a);
  printf("%d\n", f(a));

  return 0;
}

int f(int a) {
  if (a == 1){
    return a;
  } 
  else {
    return a * f(a - 1);
  }
}