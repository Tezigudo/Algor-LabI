#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n, total = 0;
  cin >> n;
  int prev = 0, m = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    // cout << total << ' ' << m << endl;
    if (x > prev) {
      total += (x - prev) + m;
      m++;
    } else {
      m = 0;
    }
    prev = x;
  }
    cout << total;
  return 0;
}