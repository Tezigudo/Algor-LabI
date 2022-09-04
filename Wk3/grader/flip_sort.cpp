#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n, count;
  bool change;
  while (cin >> n) {
    // accepted array size n
    int arr[n];
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      arr[i] = k;
    }

    // sorting zone
    count = 0;
    while (true) {
      change = false;
      // for (int i = 0; i < n; i++) {
      //   cout << arr[i];
      // }
      // cout << endl;

      for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
          int temp = arr[i];
          arr[i] = arr[i+1];
          arr[i+1] = temp;
          count++;
          change = true;
        }
      }
      if (!change) {
        break;
      }
    }
    cout << "Minimum exchange operations : " << count << endl;
  }
  return 0;
}
