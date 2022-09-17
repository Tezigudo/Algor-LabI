#include <algorithm>
#include <iostream>
using namespace std;

struct cookie {
  int val;
  cookie* next;
  cookie(int value, cookie* next_cookie = NULL) {
    val = value;
    next = next_cookie;
  }
};

cookie* find_kth_cookie(cookie* header, int k) {
  if (k != 0) {
    for (int i = -1; i < k-1 && header->next!=NULL; i++) {
      header = header->next;
    }
  }
  return header;
}

void insert(cookie* header, int k, int val, int* count) {
  cookie* new_cookie = new cookie(val);
  cookie* head_cookie = find_kth_cookie(header, k);
  new_cookie->next = head_cookie->next;
  head_cookie->next = new_cookie;
  *count+=1;
}

void eat(cookie* header, int k, int* count) {
  if(header->next==NULL || *count <= k){
    return;
  }
    cookie* head= find_kth_cookie(header, k);
    cookie* temp = head->next;
    head->next = temp->next;
    delete temp;
    *count -=1;
}

void print_cookie(cookie* header){
    while(header->next!=NULL){
        header = header->next;
        cout << header->val << endl;
    }
}

// void print_list_cookir(cookie* header){
//   while(header->next!=NULL){
//     header = header->next;
//     cout << header->val << "->";
//   }
//   cout << endl;
// }
int main() {
  int T, operation, count=0;
  cookie* header = new cookie(0);
  cin >> T;
  while (T--) {
    cin >> operation;
    switch (operation) {
        int k, num;
      case 1:
      cin >> k >> num;
      insert(header, k, num, &count);
        break;

      case 2:
      cin >> k;
      eat(header, k-1, &count);
        break;
    }
    // print_list_cookir(header);
  }
  print_cookie(header);
  return 0;
}

/*
10
2 3
1 1 1
1 0 3
1 1 7
1 3 29
2 3
1 0 90
2 1
1 5 100
2 5
*/