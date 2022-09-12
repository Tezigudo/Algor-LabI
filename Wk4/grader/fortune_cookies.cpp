#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// struct cookie {
//   int val;
//   cookie* next;
//   cookie(int value, cookie* next_cookie = NULL) {
//     val = value;
//     next = next_cookie;
//   }
// };

// cookie* find_kth_cookie(cookie* header, int k) {
//   if (k != 0) {
//     for (int i = 0; i < k; i++) {
//       header = header->next;
//     }
//   }
//   return header;
// }

// void insert(cookie* header, int k, int val) {
//   cookie* new_cookie = new cookie(val);
//   while (k--) {
//     header = header->next;
//   }
//   cookie* temp = header->next;
//   header->next = new_cookie;
//   new_cookie->next = temp;
// }


// void eat(cookie* header, int k) {
//     cookie* prev = find_kth_cookie(header, k-1);
//     cookie* next = prev->next->next;
//     delete prev->next;
//     prev->next = next;\
// }

// void print_cookie(cookie* header){
//     while(header->next!=NULL){
//         header = header->next;
//         cout << header->val << "-> ";
//     }
// }

int main() {
  int T, operation;
  // cookie* header = new cookie(0);
  vector<int> cookies;
  cin >> T;
  while (T--) {
    cin >> operation;
    switch (operation) {
        int k, num;
      case 1:
        cin >> k >> num;
        cookies.insert(cookies.begin()+k, num);
        break;

      case 2:
      cin >> k;
      if (cookies.size() >=k-1){
        cookies.erase(cookies.begin()+k);
      }
        break;
    }
  }
  for(auto itr=cookies.begin();itr!=cookies.end();itr++){
    cout << *itr << endl;
  }
  return 0;
}