#include <cstdlib>
#include <iostream>

using namespace std;

typedef int valueType;

struct ListNode {
  valueType val;
  ListNode* next;

  ListNode(valueType val, ListNode* next = 0) : val(val), next(next) {}
};

void insert_front(ListNode* header, valueType x) {
  ListNode* new_node = new ListNode(x);
  ListNode* temp = header->next;
  header->next = new_node;
  new_node->next = temp;
}

void free_list(ListNode*& header) {
    // *& is pass by referrence
    while(header->next!=NULL){
    ListNode* next = header->next;
    delete header;
    header = next;
    }
}

int main() {
  ListNode* first_header = 0;
  for (int i = 0; i < 5; i++) {
    ListNode* header = new ListNode(0);
    if (!first_header) {
      first_header = header;
    }
    for (int j = 0; j < 100000; j++) {
      insert_front(header, j);
    }
    free_list(header);
  }
  ListNode* new_header = new ListNode(0);
  new_header = new ListNode(0);
  new_header = new ListNode(0);
  int dist = abs(new_header - first_header);
  if (dist < 100) {
    cout << "ok" << endl;
  } else {
    cout << "not ok" << endl;
  }
}