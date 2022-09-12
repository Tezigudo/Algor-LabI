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