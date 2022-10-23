#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

struct node {
  int value;
  node* next;
  node(int val, node* next_node = nullptr) {
    value = val;
    next = next_node;
  }
};

struct queue {
  node* front;
  node* rear;
  int size;
  queue() {
    front = nullptr;
    rear = nullptr;
    size = 0;
  }

  bool isEmpty() { return size == 0; }

  void push(int val) {
    node* new_node = new node(val);
    if (this->isEmpty()) {
      front = new_node;
      rear = new_node;
    } else {
      rear->next = new_node;
      rear = new_node;
    }
    size++;
  }

  node* enque() {
    if (this->isEmpty()) {
      return nullptr;
    } else {
      node* temp = front;
      front = front->next;
      size--;
      return temp;
    }
  }

  void show_queue() {
    node* temp = front;
    while (temp != nullptr) {
      cout << temp->value << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

// void insert(node* head, int val){
//     node* new_node = new node(val);
//     while(head->next != nullptr){
//         head = head->next;
//     }
//     head->next = new_node;
// }

// void show_slot(node*head[]){
//     for(int i=0; i<4; i++){
//         node* temp = head[i];
//         while(temp->next != nullptr){
//             temp = temp->next;
//             cout << temp->value << " ";
//         }
//         cout << endl;
//     }
// }

void show_slot(queue q[]) {
  for (int i = 0; i < 4; i++) {
    q[i].show_queue();
  }
}

// int point(queue q[]) {
//   int point = 0;
//   for (int i = 0; i < 4; i++) {
//     node* first = q[i].enque();
//     for (int j = 0; j < 4; j++) {
//       node* second = q[j].enque();
//       if (first->value == second->value) {
//         for (int k = 0; k < 4; k++) {
//           node* third = q[k].enque();
//           if (second->value == third->value) {
//             for (int m = 0; m < 4; m++) {
//               node* fourth = q[m].enque();
//               if (third->value == fourth->value) {
//                 point++;
//               }
//               q[m].push(fourth->value);
//             }
//           }
//           q[k].push(third->value);
//         }
//       }
//       q[j].push(second->value);
//     }
//     q[i].push(first->value);
//   }
//   return point;
// }

int point(queue q[]) {
  int score = 0;
  for(int i=0; i<4; i++) {
    show_slot(q);
    cout << endl;
    node* first = q[0].enque();
    node* second = q[1].enque();
    node* third = q[2].enque();
    node* fourth = q[3].enque();

    if (first->value == second->value and second->value == third->value and
        third->value == fourth->value) {
      score++;
    }
    q[0].push(first->value);
    q[1].push(second->value);
    q[2].push(third->value);
    q[3].push(fourth->value);
  }
  return score;
}

int main() {
  // node* head0 = new node(0);
  // node* head1 = new node(0);
  // node* head2 = new node(0);
  // node* head3 = new node(0);
  // node* head[4] = {head0, head1, head2, head3};
  queue q0;
  queue q1;
  queue q2;
  queue q3;
  queue q[4] = {q0, q1, q2, q3};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int val;
      cin >> val;
      q[j].push(val);
      // insert(head[j], val);
    }
  }
  cout << point(q) << endl;
  show_slot(q);

  int maximum = 0;
  for (int i = 0; i < 4; i++) {
    node* first = q[i].enque();
    for (int j = 0; j < 4; j++) {
      node* second = q[j].enque();
      if (first->value == second->value) {
        for (int k = 0; k < 4; k++) {
          node* third = q[k].enque();
          if (second->value == third->value) {
            for (int m = 0; m < 4; m++) {
              node* fourth = q[m].enque();
              if (third->value == fourth->value) {
                int score = point(q);
                cout << endl << endl;
                show_slot(q);
                cout << endl << "point: " << score << endl;
                // maximum = max(maximum, point(q));
              }
              q[m].push(fourth->value);
            }
          }
          q[k].push(third->value);
        }
      }
      q[j].push(second->value);
    }
    q[i].push(first->value);
  }

  // show_slot(q);

  cout << maximum << endl;
  return 0;
}

// #include<iostream>
// #include<cmath>
// #include<algorithm>
// #include<string>
// using namespace std;

// void init_slot(int head[4][4]){
//     for(int i=0; i<4; i++){
//         for(int j=0; j<4; j++){
//             cin >> head[j][i];
//         }
//     }
// }

// void show_slot(int head[4][4]){
//     for(int i=0; i<4; i++){
//         for(int j=0; j<4; j++){
//             cout << head[j][i] << " ";
//         }
//         cout << endl;
//     }
// }

// int point(int head[4][4]){
//     int point = 0;
//     for(int i=0; i<4;i++){
//         if(head[i][0] == head[i][1] == head[i][2] == head[i][3]){
//             point += 1;
//         }
//     }
//     return point;
// }

// int main(){
//     int head[4][4];
//     init_slot(head);
//     show_slot(head);
//     cout << point(head);
//     return 0;
// }