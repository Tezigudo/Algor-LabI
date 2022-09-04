#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n, total = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    int temp;
    cin >> k;
    if (k >= 1000) {
      k = 1000;
      cin >> temp;
      i++;
    };
    total += k;
  }
  cout << total << endl;
  return 0;
}