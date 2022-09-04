#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

bool find(int arr[], int element, int size) {
  // do a linear search
  for (int i = 0; i < size; i++) {
    if (arr[i] == element) {
      return true;
    }
  }
  return false;
}

int main() {
  int n, k, count = 0, j = 0;
  cin >> n >> k;
  if(k==1){
    cout << n;
    return 0;
  }
  int used[n - 1];
  while (j != n - 1) {
    for (int i = 1; i <= n; i++) {
      if (!find(used, i, j + 1)) {
        count++;
        if (count % k == 0) {
          used[j] = i;
          j++;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++){
    if(!find(used, i, n-1)){
        cout << i;
    }
  }
  return 0;
}