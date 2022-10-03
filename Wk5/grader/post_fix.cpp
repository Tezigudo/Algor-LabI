#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

typedef double ValueType;

struct ListNode {
  ValueType val;
  ListNode* next;

  ListNode(ValueType val, ListNode* next = nullptr) : val(val), next(next) {}
};

ValueType pop(ListNode*& head) {
  ListNode* next = head->next;
  ValueType x = head->val;
  delete head;
  head = next;

  return x;
}

void push(ListNode*& head, ValueType x) {
  ListNode* new_node = new ListNode(x, head);
  head = new_node;
}

int main() {
  string buffer;

  ListNode* head = nullptr;

  do {
    cin >> buffer;
    if (buffer.at(0) == '=') {
      break;
    } else if ((buffer.at(0) >= '0') && (buffer.at(0) <= '9')) {
      double val = stod(buffer);
      // *****************************
      // insert val into the top of the stack
      push(head, val);

    } else {
      // *****************************
      // buffer is an operator.
      ValueType val_1, val_2, result;
      switch (buffer.at(0)) {
        case '+':
          val_1 = pop(head);
          val_2 = pop(head);
          result = val_1 + val_2;
          break;
        case '-':
          val_1 = pop(head);
          val_2 = pop(head);
          result = val_2 - val_1;
          break;
        case '*':
          val_1 = pop(head);
          val_2 = pop(head);
          result = val_1 * val_2;
          break;
        case '/':
          val_1 = pop(head);
          val_2 = pop(head);
          result = val_2 / val_1;
          break;

        default:
          break;
      }
      push(head, result);
    }
  } while (true);
  cout << fixed << setprecision(4) << head->val << endl;
}