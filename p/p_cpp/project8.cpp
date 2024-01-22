#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
#define N 3

using namespace std;

//배열에 1부터 N까지의 수를 랜덤으로 입력하는 함수
void random_f(int* arr, int size) {
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % size + 1;
    for (int j = 0; j < i; j++) {
      if (arr[i] == arr[j]) i--;
    }
  }
}

int main() {
  int count_N = 0;
  int N_c = N * N;
  while (N_c != 0) {
    N_c /= 10;
    count_N += 1;
  }
  int arr_main[N][N];
  int arr_i[N] = {};
  int arr_j[N] = {};
  int i_j = 0;
  int j_i = 0;
  for (int T = 0; T < 1;) {
    int arr_main_c[N * N];
    random_f(arr_main_c, N * N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        arr_main[i][j] = arr_main_c[N * i + j];
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        arr_i[i] += arr_main[i][j];
        arr_j[i] += arr_main[j][i];
        for (int k = 0; k < N - 1; k++) {
          if (arr_i[k] == arr_i[k + 1]) T = 1;
          else T = 0;
          if (arr_j[k] == arr_j[k + 1]) T = 1;
          else T = 0;
        }
      }
    }
  }
  cout << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << arr_main[i][j] << "   ";
      for (int k = 0; k < count_N; k++) {
         if (pow(10, k) <= arr_main[i][j] && arr_main[i][j] < pow(10, k + 1)) {
          for (int l = 0; l < count_N - k - 1; l++) {
            cout << " ";
          }
        }
      }
    }
    cout << endl << endl;
  }

  return 0;
}