//비트 연산자 
// & -> 둘다 1인 경우 1
// | -> 둘중 하나라도 1인 경우 1
// ^ -> 둘이 같으면 0, 다르면 1
// ~ -> 0이면 1, 1이면 0
//plus) 원하는 자리의 비트르 빼고 싶을 때 &= ~ 사용

#include <iostream>

using namespace std;

int i = 0;

namespace my1 {
  int a = 0;
  void func();
}

namespace my2 {
  int a = 0;
  void func();
}


int main() {
  cout
  << "hello world!" << endl;

  my1::func();
  my1::func();
  my1::func();
  my2::func();

  cout
  << my1::a << endl
  << my2::a << endl;
  

  return 0;
}

void my1::func() {
  a++;
}

void my2::func() {
  a++;
}
