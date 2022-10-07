#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

struct node {
  int val;
  node* next;
  node* prev;
  node(int value, node* next_node = nullptr, node* prev_node = nullptr) {
    val = value;
    next = next_node;
  }
};

void insert_front(node* header, int val, node* footer, int* size) {
  while (header->next != footer) {
    header = header->next;
    if (header->val == val) {
      header = header->prev;
      node* temp = header;
      while (temp->next != footer) {
        // node* temptemp = temp;
        temp = temp->next;
        // delete temptemp;
        *size -= 1;
      }
      header->next = footer;
      footer->prev = header;
      return;
    }
  }
  node* new_node = new node(val);
  header->next = new_node;
  new_node->prev = header;
  footer->prev = new_node;
  new_node->next = footer;
  *size += 1;
}

void insert_back(node* header, int val, node* footer, int* size) {
  while (footer->prev != header) {
    // cout << footer->val << "::( " << endl << endl;
    footer = footer->prev;
    if (footer->val == val) {
      footer = footer->next;
      node* temp = footer;
      while (temp->prev != header) {
        // node* temptemp = temp;
        temp = temp->prev;
        // delete temptemp;
        *size -= 1;
      }
      footer->prev = header;
      header->next = footer;
      return;
    }
  }
  node* new_node = new node(val);
  footer->prev = new_node;
  new_node->next = footer;
  header->next = new_node;
  new_node->prev = header;
  *size += 1;
}

void show_ball(node* header, node* footer) {
  while (header->next != footer) {
    header = header->next;
    cout << header->val << "-> ";
  }
  cout << endl;
}

int main() {
  node* header = new node(0);
  node* footer = new node(0);
  header->next = footer;
  footer->prev = header;
  int N;
  int size = 0;
  cin >> N;
  while (N--) {
    int operation, val;
    cin >> operation >> val;
    switch (operation) {
      case 0:
        insert_front(header, val, footer, &size);
        break;

      case 1:
        insert_back(header, val, footer, &size);
        break;
    }
    // show_ball(header, footer);
  }
  // cout << size(header, footer);
  cout << size;
  return 0;
}