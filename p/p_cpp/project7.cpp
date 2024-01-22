#include <iostream>
#include <random>
#include <ctime>
#define N 25

using namespace std;

//배열에 1부터 45까지의 수를 랜덤으로 입력하는 함수
void random_f(int*, int);

int rand_arr[N];

int main() {
  random_f(rand_arr, N);
  for (int i = 0; i < N; i++) {
    cout << rand_arr[i] << "   ";
    if (rand_arr[i] < 10) {
      cout << " ";
    }
    if (i % 5 == 4) {
      cout << endl << endl;
    }
  }
  cout << endl;

  return 0;
}

void random_f(int* arr, int size) {
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % size + 1;
    for (int j = 0; j < i; j++) {
      if (arr[i] == arr[j]) i--;
    }
  }
}