#include <iostream>

using namespace std;

struct people {
  int id;
  people* next;
  people(int ids, people* nexts) {
    id = ids;
    next = NULL;
  }
};

void insert(people* header, int id) {
  people* new_peep = new people(id, NULL);
  while (header->next != NULL) {
    header = header->next;
  }
  header->next = new_peep;
}

void serve(people* header) {
  people* temp = header->next;
  header->next = temp->next;
  cout << temp->id << endl;
  delete temp;
}

int count_queue(people* header) {
    int count =0;
    while (header->next != NULL) {
      header = header->next;
      count++;
    }
    return count;
}

int main() {
  people* header = new people(0, NULL);
  int m, t;
  cin >> m;
  while (m--) {
    cin >> t;
    switch (t) {
      case 1:
        int peep;
        cin >> peep;
        while (peep--) {
          int id;
          cin >> id;
          insert(header, id);
        }
        break;

      case 2:
        serve(header);
        break;
    }
  }
  cout << count_queue(header);
  return 0;
}

/*
7
1 2 4 3
2
1 3 8 6 2
2
2
2
1 6 10 20 30 40 50 60
*/