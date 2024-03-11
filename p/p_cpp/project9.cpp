#include <iostream>

using namespace std;

int *p;
int size;

int main() 
{
  size = 4;
  p = (int *)malloc(16);
  for (int i = 0; i < size; i++) {
    p[i] = i + 1;
  }
  cout << sizeof(p) << endl;


  free(p);
  return 0;
}