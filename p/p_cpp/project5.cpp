#include <iostream>
using namespace std;

int card_score(int);

int main() {
	cout << "Hello World!" << endl;
	cout << card_score(5) << endl;


	return 0;	
}


int card_score(int card_num) {
  if ((card_num + 1) % 13 < 10 && (card_num + 1) % 13 > 0) return (card_num + 1) % 13;
  else return 10;
}