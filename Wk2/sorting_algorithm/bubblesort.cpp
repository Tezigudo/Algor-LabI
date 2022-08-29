/*Bubble sort is probably the easiest-to-understand sorting algorithm. It
repeatedly swaps consecutive pairs of elements in an array which are out of
order until everything is sorted.

The code below implements the bubble sort to sort an array with n elements
ascendingly (from smallest to largest). Complete the blanks.*/

#include <iostream>
using namespace std;

void bubble_sort(int a[], int n) {
  while (true) {
    bool changed = false;
    for (int i = 0; i < n - 1; i++) {
      // compares a[i] with a[i+1]
      if (a[i] > a[i + 1]) {
        // wrong order, swap them;  don't forget to update changed variable
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
        changed = true;
      }
    }
    if (!changed) break;
  }
}

int main() {
  int a[1000];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  bubble_sort(a, n);
  for (int i = 0; i < n; i++) cout << a[i] << endl;
}