#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
  Node* prev;
  Node(int value, Node* next_node = NULL, Node* prev_node = NULL) {
    val = value;
    next = next_node;
    prev = prev_node;
  }
};

// void print_list(Node* header, int size) {
//   while (size--) {
//     cout << header->val;
//     header = header->next;
//     cout << "->";
//   }
//   cout << endl;
// }

Node* init_card(int size) {
  Node* header = new Node(0);
  Node* temp = header;
  for (int i = 0; i < size; i++) {
    int x;
    cin >> x;
    Node* new_node = new Node(x);
    if (header != NULL) {
      new_node->prev = header;
    }
    header->next = new_node;
    header = header->next;
  }

  Node* prev = header;
    // cout << header->val << "  " << header->prev->val << endl;
  header = temp->next;
  // cout << header->val << "  " << endl;
  if (header != NULL) {
    header->prev = prev;
    prev->next = header;
  }
  return header;
}

int main() {
  int n, m;
  cin >> n >> m;
  Node* now = init_card(n);
  Node* header = now;
  // print_list(header, n);
  while (m--) {
    int x;
    cin >> x;
    int count = 0;
    while (x - now->val > 0) {
      count++;
      x -= now->val;
      if (x - now->next->val <= 0) {
        break;
      }
      now = now->next;
    }

    if (count == 0) {
      // Node* target = now;
      // now = now->next;
      // while(now->next!=target){
      //   now = now->next;
      // }
      now = now->prev;
    }
        // print_list(header, n);
        // cout << now->val << "   " << now->next->val << "   " << now->prev->val<< endl;
        // cout << now->next->val << "   " << (now->next->next)<< "   " << now->next->prev->val<< endl;
    Node* temp = now->next;
    now->next = temp->next;
    now->next->prev = temp->prev;


    // cout << temp->val << endl;
    if (temp == header) {
      header = header->next;
    }
    delete temp;
    now = now->next;
    n--;
    // print_list(header, n);
  }
  // print_list(now, n);
  for (int i = 0; i < n; i++) {
    cout << header->val << endl;
    header = header->next;
  }
  return 0;
}