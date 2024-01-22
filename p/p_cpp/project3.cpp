#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int player_card_num[26];
int dealer_card_num[26];
int dealer_card_count;
int dealer_score;
int w;

void pick_rand_num_arr_f();
void card_shape_num_f(int);
void game_turn();
void print_card_f(int);
void dealer_f();
int card_score(int);

int main() {
  int coin = 500;
  int bet;
  pick_rand_num_arr_f();
  cout << "your coin : 500" << endl;
  do {
    srand((unsigned int)time(NULL));
    bet = 0;
    do {
      cout << "bet : ";
      cin >> bet;
      if (coin < bet) bet = 0;
    } while (bet == 0);
    game_turn();
    if (w == 0) coin += bet;
    else coin -= bet;
    cout << "your coin : " << coin << endl;
  } while (coin != 0);
  

  return 0;
}

void pick_rand_num_arr_f() {
  int arr[52];
  for(int i = 0; i < 52; i++) {
    arr[i] = rand() % 52;
    for(int j = 0; j < i; j++) {
      if (arr[i] == arr[j]) i--;
    }
    if (i < 26) {
      player_card_num[i] = arr[i];
    }
    else {
      dealer_card_num[i - 26] = arr[i];
    }    
  }
}

void card_shape_num_f(int a1) {
  if (a1 / 13 == 0) cout << "SPADE";
  else if (a1 / 13 == 1) cout << "DIAMOND";
  else if (a1 / 13 == 2) cout << "HEART";
  else if (a1 / 13 == 3) cout << "CLOVER";
  else cout << "ERROR";
  if (a1 % 13 == 11) cout << "_JACK ";
  else if (a1 % 13 == 12) cout << "_QUEEN ";
  else if (a1 % 13 == 13) cout << "_KING ";
  else if (a1 % 13 == 0) cout << "_ACE ";
  else cout << "_" << (a1 % 13) + 1 << " ";
}

void game_turn() {
  int player_card_count = 2;
  dealer_card_count = 2;
  int game_state = 1;
  int player_score = card_score(player_card_num[0]) + card_score(player_card_num[1]);
  cout << "dealer : ";
  card_shape_num_f(dealer_card_num[0]);
  cout << endl << "your : ";
  print_card_f(2);
  cout << "your score : " << player_score << endl;
  while (game_state == 1 && player_score <= 21) {
    cout << "Enter 1 if you want pick, enter 2 if not" << endl;
    cin >> game_state;
    cout << endl;
    if (game_state == 1) {
      player_score += card_score(player_card_num[player_card_count]);
      cout << "your : ";
      print_card_f(++player_card_count);
      cout << player_score << endl;
    }
    
  }
  cout << "Game Over" << endl << "your : ";
  print_card_f(player_card_count);
  cout << "your score : " << player_score << endl << "dealer : ";
  dealer_f();
  cout << endl << "dealer_score : " << dealer_score << endl;

  if (player_score > 21) {
    cout << "DEFEAT" << endl;
    w = 1;
  }
  else if (dealer_score > 21) {
    cout << "WIN" << endl;
    w = 0;
  }
  else if (dealer_score <= player_score) {
    cout << "WIN" << endl;
    w = 0;
  }
  else {
    cout << "DEFEAT" << endl;
    w = 1;
  }


}

void print_card_f(int card_count) {
  for (int i = 0; i < card_count; i++) {
    card_shape_num_f(player_card_num[i]);
  }
  cout << endl;
}

void dealer_f() {
  dealer_score = 0;
  for (int i = 0; i < 26; i++) {
    if (dealer_score < 17) {
      card_shape_num_f(dealer_card_num[i]);
      dealer_score += card_score(dealer_card_num[i]);
    }
    else i = 26;
  }
}

int card_score(int card_num) {
  if ((card_num + 1) % 13 < 10 && (card_num + 1) % 13 > 0) return (card_num + 1) % 13;
  else return 10;
}