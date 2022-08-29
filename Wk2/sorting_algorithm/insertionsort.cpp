/*Insertion sort is another simple sorting algorithm. It repeatedly picks new
element to insert into an already sorted array (which is initially empty).

The code below implements the insertion sort to sort an array with n elements
ascendingly (from smallest to largest). Complete the blanks.*/

#include <iostream>
using namespace std;

void insertion_sort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    // try to insert a[i] in to the already sorted array a[0],...,a[i-1]
    int j =i; 
    while (j > 0) {
      // our current element is in a[j]

      // compares a[j] with a[j-1]
      if (a[j] < a[j-1]) {
        // need to swap a[j] with its preceding element
        swap(a[j], a[j-1]);
      } else {
        break;
      }
      j--;
    }
  }
}

int main() {
  int a[1000];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  insertion_sort(a, n);
  for (int i = 0; i < n; i++) cout << a[i] << endl;
}