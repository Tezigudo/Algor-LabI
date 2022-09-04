#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int k, n, m, x, y;

  while (cin >> k) {
    if(k==0){
      break;
    }
    cin >> n >> m;
    for (int i = 0; i < k; i++) {
      cin >> x >> y;
      if (x == n or y == m) {
        cout << "divisa" << endl;
        continue;
      }
      if (y > m) {
        cout << 'N';
      } else {
        cout << 'S';
      }

      if (x > n) {
        cout << 'E';
      } else {
        cout << 'O';
      }
      cout << endl;
    }
  }
  return 0;
}