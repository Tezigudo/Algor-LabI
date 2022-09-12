#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

struct Dog {
  int age;
  double weight;
  double speed;
};

typedef Dog ElementT;

bool operator==(Dog& d1, Dog& d2) {
  return (d1.age == d2.age) && (d1.weight == d2.weight) &&
         (d1.speed == d2.speed);
}

void append_list(ElementT* items, int* count, ElementT new_items) {
    items[*count] = new_items;
    *count+=1;
}

int find(ElementT* items, int count, ElementT target) {
    for (int i=0;i<count;i++){
        if(items[i]==target){
            return i;
        }
    }
    return -1;
}

Dog read_dog() {
  Dog d;
  cin >> d.age >> d.weight >> d.speed;
  return d;
}

int main() {
  int n;
  Dog dogs[1000];
  int dog_count = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    Dog new_dog = read_dog();
    append_list(dogs, &dog_count, new_dog);
  }
  Dog target_dog = read_dog();
  cout << find(dogs, dog_count, target_dog) << endl;
}
