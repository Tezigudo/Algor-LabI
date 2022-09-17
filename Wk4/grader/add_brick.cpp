#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

typedef vector<vector<int> > nested;

tuple<int, int, int> compute_brick(int top, int bottom_left, int bottom_right) {
  int bottom_mid = (top - bottom_left - bottom_right) / 2;
  int mid_right = bottom_mid + bottom_right;
  int mid_left = bottom_mid + bottom_left;

  return {bottom_mid, mid_left, mid_right};
}

nested init_wall(int size) {
  nested wall;
  for (int i = 1; i <= size; i++) {
    vector<int> brick;
    for (int j = 0; j <= i-1; j++) {
      brick.push_back(0);
    }
    wall.push_back(brick);
    }
  return wall;
  }


void print_wall(nested wall) {
  cout << '[' << endl;
  for (int i = 0; i < wall.size(); i++) {
    cout << '[';
    for (int j = 0; j < wall[i].size(); j++) {
      cout << wall[i][j];
      if (j!=wall[i].size()-1){
        cout << ", ";
      }
    }
    cout << "]";
    if (i!=wall.size()-1){
      cout << ',' << endl;
    }else{
      cout << endl << ']';
    }
  }
}

// void initialize_wall(int arr[9][9]) {
//   for (int i = 0; i < 9; i++) {
//     for (int j = 0; j < 9; j++) {
//       arr[i][j] = 0;
//     }
//   }
// }

int main() {
  //   int wall[9][9];
  //   initialize_wall(wall);
  nested small_wall = init_wall(9);
  print_wall(small_wall);

  return 0;
}
