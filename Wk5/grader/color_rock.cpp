#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool check_pop(vector<int> arr, int k) {
  int size = arr.size();
  if (size < k) {
    return false;
  }
  int val = arr[-1];
  for (int i=1;i<=k;i++) {
    if (arr[-i]!=val){
        return false;
    }
  }
  return true;
}

// int main() {
//   int n, k;
//   vector<int> arr;
//   cin >> n >> k;
//     for(int i=0;i<n;i++){
//         int x;
//         cin >> x;
//         arr.push_back(x);
//         if (check_pop(arr, k)){
//             for(int j=0;j<k;j++){
//                 arr.pop_back();
//             }
//         }
//     }
//     cout << arr.size();
//   return 0;
// }

int main() {
  int n, k;
  cin >> n >> k;
  int arr[n], prev, count = 0, c = 0;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    arr[i] = x;
    c++;
    if (arr[i]==prev){
      count++;
    }else{
      count=0;
      prev = arr[i];
    }
    // cout << count << "  " << k << endl;
    if (count==k-1){
      // cout << "yes" << endl;
      count=0;
      c-=k;
      prev = arr[i-k-1];
    }
  }
  cout << c;
}