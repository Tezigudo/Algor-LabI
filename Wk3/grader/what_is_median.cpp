#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n, med, i = 0;
  int arr[10000];
  // inserted to sorted array
  while (cin >> n) {
    arr[i] = n;
    int j = i;
    while (j > 0) {
      if (arr[j] < arr[j - 1]) {
        // need to swap a[j] with its preceding element
        swap(arr[j], arr[j - 1]);
      } else {
        break;
      }
      j--;
    }
    i++;
    med = i / 2;
    if (i % 2 != 0) {
      cout << arr[med];
    } else {
      cout << (arr[med - 1] + arr[med]) / 2;
    }
    cout << endl;
  }
  return 0;
}