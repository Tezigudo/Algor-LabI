#include <algorithm>
#include <iostream>
// #include <queue>
#include <string>
using namespace std;

struct node {
  int index;
  int priority;
  node* next;
  node(int prior, int ind, node* next = nullptr) {
    this->priority = prior;
    this->index = ind;
    this->next = next;
  }
};

struct queue {
  node* front;
  node* rear;
  queue(node* front_node = nullptr, node* rear_node = nullptr) {
    this->front = front_node;
    this->rear = rear_node;
  }

  bool is_empty() { return this->front == nullptr; };

  void push(node* new_node) {
    if (this->is_empty()) {
      this->front = new_node;
      this->rear = new_node;
    } else {
      this->rear->next = new_node;
      this->rear = this->rear->next;
    }
  }

  void push(int prior, int ind) {
    node* new_node = new node(prior, ind);
    this->push(new_node);
  }

  node* enque() {
    node* now = this->front;
    if (not this->is_empty()) {
      if (this->front == this->rear) {
        this->front = nullptr;
        this->rear = nullptr;
      } else {
        this->front = this->front->next;
      }
    }
    return now;
  }

  void show_queue() {
    if (this->is_empty()) {
      cout << "the queue is empty" << endl;
      return;
    }
    node* temp = this->front;
    while (temp->next != nullptr) {
      cout << temp->index << "\t";
      temp = temp->next;
    }
    cout << endl;
  }
};

bool is_ready(queue printer) {
  if (printer.is_empty()) {
    return 0;
  }
  node* front = printer.enque();
  int prior = front->priority;
  while (not printer.is_empty()) {
    if (printer.enque()->priority > prior) {
      return false;
    }
  }
  return true;
}

int main() {
  int testcase;
  cin >> testcase;
  while (testcase--) {
    int n, m, time = 0;
    cin >> n >> m;
    queue printer;
    for (int i = 0; i < n; i++) {
      int prior;
      cin >> prior;
      node* new_node = new node(prior, i);
      printer.push(new_node);
    }

    // printer.show_queue();

    while (not printer.is_empty()) {
      node* front = printer.front;
      if (!is_ready(printer)) {
        printer.enque();
        printer.push(front);
      } else {
        printer.enque();
        time++;
        if (front->index == m) {
          break;
        }
      }
    }
    cout << time << endl;
  }
  return 0;
}