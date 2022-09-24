#include <iostream>

using namespace std;

const int MAX_N = 10010;

char names[MAX_N][20];

int main() {
  char cmd[10];
  int n;

  cin >> n;

  int ncount = 0;
  for (int i = 0; i < n; i++) {
    cin >> cmd;

    if (cmd[0] == 'S') {
      cin >> names[ncount];

      // ...

      ncount++;
    } else if (cmd[0] == 'K') {
      if (ncount > 0) {
        ncount--;
      }

    } else {
      if (ncount == 0) {
        cout << "Not in a dream" << endl;
      } else {
        cout << names[ncount-1] << endl;
      }
    }
  }

  return 0;
}
