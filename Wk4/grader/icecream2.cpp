#include <iostream>

using namespace std;

struct people {
  int id;
  int flavour;
  people* next;
  people(int ids, int flavours, people* nexts) {
    id = ids;
    flavour = flavours;
    next = NULL;
  }
};

void insert(people* header, int id, int flavour) {
  people* new_peep = new people(id, flavour, NULL);
  while (header->next != NULL) {
    header = header->next;
  }
  header->next = new_peep;
}

void serve(people* header, int flav[]) {
  people* temp = header->next;
  header->next = temp->next;
  flav[temp->flavour-1] += 1;
  cout << temp->id << endl;
  delete temp;
}

int count_queue(people* header) {
  int count = 0;
  while (header->next != NULL) {
    header = header->next;
    count++;
  }
  return count;
}

void initialize_flavour(int arr[]) {
  for (int i = 0; i < 20; i++) {
    arr[i] = 0;
  }
}

void print_flav(int flav[]) {
  for (int i = 0; i < 20; i++) {
    cout << flav[i];
    if (i != 19) {
      cout << " ";
    }
  }
}

int main() {
  people* header = new people(0, 0, NULL);
  int m, t;
  int flavours[20];
  initialize_flavour(flavours);

  cin >> m;
  while (m--) {
    cin >> t;
    switch (t) {
      case 1:
        int peep;
        cin >> peep;
        while (peep--) {
          int id, flav;
          cin >> id >> flav;
          insert(header, id, flav);
        }
        break;

      case 2:
        serve(header, flavours);
        break;
    }
  }
  cout << count_queue(header) << endl;
  print_flav(flavours);
  return 0;
}

/*
7
1 2 4 1 3 2
2
1 3 8 5 6 2 2 7
2
2
2
1 6 10 1 20 1 30 1 40 1 50 1 60 1
*/

// //jin code
// #include <iostream>
// using namespace std;

// typedef int ValueType;
// struct ListNode {
//   ValueType val;
//   ValueType flavor;
//   ListNode* next;

//   ListNode(ValueType v, ValueType f,ListNode* nxt=0)
//     : val(v), flavor(f), next(nxt) {}
// };

// ListNode* front = nullptr;
// ListNode* rear = nullptr;

// void append(ListNode*& front, ListNode*& rear, ValueType x, ValueType f)
// {
//   ListNode* n = new ListNode(x, f);
//   if (rear != nullptr) {
//     rear->next = n;
//     rear = n;
//   } else {
//     front = rear = n;
//   }
// }

// ValueType extract(ListNode*& front, ListNode*& rear)
// {
//   ValueType v = front->val;

//   ListNode* new_front = front->next;
//   delete front;
//   front = new_front;
//   if (front == nullptr) {
//     rear = nullptr;
//   }
//   return v;
// }

// int main()
// {
//   int m;
//   int a[20] = {0, 0 , 0 , 0 , 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};

//   cin >> m;
//   for (int i = 0; i < m; ++i) {
//     int t;

//     cin >> t;
//     if (t == 1) {
//       int n;
//       cin >> n;
//       // your code here
//       for (int j = 0; j < n; j++){
//         int id, fv;
//         cin >> id >> fv;
//         append(front, rear, id, fv);
//       }
      
//     } else {
//       // here, t = 2.  Call someone to the queue.
//       if (t == 2){
//         cout << front->val << endl;
//         for (int i = 1; i <= 20 ;i++){
//           if (front->flavor == i){
//             a[i-1] += 1;
//           }
//         }
        
//         extract(front, rear);
        

//       }
//     }
//   }

//   // you have to print the number of remaining customers as well.
//   // iterate the rest of the list here...
  
//   int num = 0;
//   ListNode* now_list = front;
//   while (now_list != nullptr){
//     num++;
//     now_list = now_list->next;
//   }
//   cout << num << endl;

//   for (int j = 0; j < 20; j++){
//     cout << a[j] << " ";
//      (j == 19){
//       cout << a[j] << endl;
//     }
//   }

// }