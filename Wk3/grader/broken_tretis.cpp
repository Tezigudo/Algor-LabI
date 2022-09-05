#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int max(int arr[], int size, int ind=0) {
  int maximum = -99999;
  for (int i = ind; i < ind+size; i++) {
    if (arr[i] > maximum) {
      maximum = arr[i];
    }
  }
  return maximum;
}

int main() {
  int cols[10];
  // initialize column
  for (int i = 0; i < 10; i++) {
    cols[i] = 0;
  }

  int n;
  cin >> n;
  while (n--) {
    char sym;
    int col;
    cin >> sym >> col;

    int max_of_col;
    switch (sym) {
      case '-':
        max_of_col = max(cols, 4, col-1);
        for (int j = col - 1; j < col + 3; j++) {
          cols[j] = max_of_col+1;
        }
        break;
      case 'o':
      max_of_col = max(cols, 2, col-1);
        cols[col - 1] = max_of_col+2;
        cols[col] = max_of_col+2;
        break;

      case 'i':
        cols[col - 1] += 4;
        break;
      default:
        break;
    }
  }

  cout << max(cols, 10);
  return 0;
}

/*
5
- 1
o 1
i 4
- 2
i 10

5
- 1
- 5
- 1
- 5
o 9
*/
