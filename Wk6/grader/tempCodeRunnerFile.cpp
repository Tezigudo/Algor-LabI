#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct node {
  int index;
  int priority;
  // node* next;
  node(int prior, int ind) {
    this->priority = prior;
    this->index = ind;
    // this->next = next;
  }
};

void show_queue(queue<node*> printer) {
  while (not printer.empty()) {
    cout << printer.front()->index << "  ";
    printer.pop();
  }
  cout << endl;
}

bool is_ready(queue<node*> printer) {
  int prior = printer.front()->priority;
  show_queue(printer);

  printer.pop();
  while (not printer.empty()) {
    show_queue(printer);
    int val = printer.front()->priority;
    if (val > prior) {
      return false;
    }
    printer.pop();
  }
  return true;
}

int main() {
    int testcase;
    cin >> testcase;
    while (testcase--) {
    int n, m, time = 0;
    cin >> n >> m;
    queue<node*> printer;
    for (int i = 0; i < n; i++) {
      int prior;
      cin >> prior;
      node* new_node = new node(prior, i);
      printer.push(new_node);
    }

      // show_queue(printer);
      while (!printer.empty() and (printer.front()->index != m or not is_ready(printer))) {
        node* now = printer.front();
        printer.pop();
        if (is_ready(printer)) {
          cout << "yatta" << endl;
          time++;
        } else {
          printer.push(now);
        }
      }
      time++;
      cout << time << endl;
    }
    return 0;

}