#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

struct player {
  int point;
  player* next;
  player(int points, player* next_player = NULL) {
    point = points;
    next = next_player;
  }
};

void init_player(player* header, int n) {
  while (n--) {
    player* new_player = new player(0);
    header->next = new_player;
    header = header->next;
  }
}

// void print_player(player* header) {
//   while (header->next != NULL) {
//     header = header->next;
//     cout << header->point;
//     if (header->next != NULL) {
//       cout << "->";
//     }
//   }
// }

void insert_player(player* angel) {
  player* new_player = new player(0);
  new_player->next = angel->next;
  angel->next = new_player;
}

int main() {
  player* header = new player(0);
  int n, m;
  cin >> n >> m;
  init_player(header, n);
  player* angel = header->next;
  // m is action
  while (m--) {
    int action;
    cin >> action;
    switch (action) {
      case 0:
        angel = header->next;
        break;
      case 1:
        angel = angel->next;
        break;

      case 2:
        insert_player(angel);
        break;
      case 3:
        int x;
        cin >> x;
        angel->point += x;
        break;
    }
  }
//   print_player(header);
    while(header->next!=NULL){
        header = header->next;
        cout << header->point;
        if (header->next!=NULL){
            cout << ' ';
        }
    }
  return 0;
}