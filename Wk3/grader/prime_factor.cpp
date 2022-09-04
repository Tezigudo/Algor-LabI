#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

bool is_prime(int n) {
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i < sqrt(n) + 1; i++) {
    if (n % i == 0 and i != n) {
      return false;
    }
  }
  return true;
}

// better solution by dol
int main(){
  int n, count = 0;
  cin >> n;
  for (int i=2;i<=n;i++){
    if(n%i==0 and is_prime((i))){
      count++;
    }
  }
  cout << count;
}


// *my solution
// bool find(int arr[], int element, int size) {
//   // do a linear search
//   for (int i = 0; i < size; i++) {
//     if (arr[i] == element) {
//       return true;
//     }
//   }
//   return false;
// }

// int main() {
//   int n, count = 0;
//   cin >> n;
//   int prime[100];
//   while (n > 1) {
//     int i = 1;
//     while (n % i != 0 || !is_prime(i)) {
//       i++;
//     }
//     n = n / i;
//     if (!find(prime, i, count)) {
//       prime[count] = i;
//       count++;
//     }
//   }
//   cout << count;
//   return 0;
// }


