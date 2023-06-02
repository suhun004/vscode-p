#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int rand_number[9];
int enter_number[9];
int a, b;
int goal = 0;

void pick_number_f(int a); //rand_number[]에 1부터 a까지의 수를 랜덤으로 배열하여 입력

int main()
{
  srand(time(NULL));
  printf("원하는 자릿수를 입력하세요\n");
  scanf("%d", &a);
  pick_number_f(a);
  for (int i = 0; i < a; i++) {
    goal += rand_number[i] * pow(10, a - 1 - i);
  }
  printf("%d\n", goal);

  return 0;
}

void pick_number_f(int a) {
  for (int i = 0; i < a; i++) {
    rand_number[i] = rand() % a + 1;
    for (int j = 0; j < i; j++) {
      if (rand_number[i] == rand_number[j]) i--;
    }
  }
}

