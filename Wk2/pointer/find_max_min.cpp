#include <iostream>

using namespace std;

void find_max_min(int b[], int n, int *max, int *min) {
    *max = -9999;
    *min = 9999;
  for (int i = 0; i < n; i++) {
    cout << endl;
    if (b[i] > *max) {
    //   max = &b[i];
      *max = b[i];
    } if (b[i] < *min) {
    //   min = &b[i];
      *min = b[i];
    }
  }
}

int main() {
  int a[1000];
  int n;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int mx, mn;
  find_max_min(a, n, &mx, &mn);

  cout << "max = " << mx << endl;
  cout << "min = " << mn << endl;
}
