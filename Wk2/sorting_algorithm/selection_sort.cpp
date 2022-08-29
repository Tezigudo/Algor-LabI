/*Selection sort is probably one of the easiest to analyze. It repeatedly
chooses the smallest element and moves it to the front. (Or, vise versa,
choosing the the largest element also works.)

The code below implements the selection sort to sort an array with n elements
ascendingly (from smallest to largest). Complete the blanks.*/

#include <iostream>
using namespace std;

void selection_sort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_idx = 0;
    int min_val = 99999;

    // find smallest elements from a[i] ... a[n-1]
    for (int j = i; j < n; j++) {
      if (a[j] < min_val) {
        // update min_idx and min_val accordingly
        min_idx = j;
        min_val = a[j];
      }
    }
    // swap a[i] with the smallest element
    swap(a[i], a[min_idx]);
  }
}

int main() {
  int a[1000];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  selection_sort(a, n);
  for (int i = 0; i < n; i++) cout << a[i] << endl;
}