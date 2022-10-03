#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node{
  int val;
  node* next;
  node(int val, node* next = nullptr){
    this->val = val;
    this->next = next;
  }
};

struct stack{
  node* top;
  int size;
  stack(node* top_node = nullptr){
    this->top = top_node;
    this->size = 0;
  }

  bool is_empty(){ return this->top == nullptr; };

  void push(node* new_node){
    if(this->is_empty()){
      this->top = new_node;
    }else{
      new_node->next = this->top;
      this->top = new_node;
    }
    this->size++;
  }

  void push(int val){
    node* new_node = new node(val);
    this->push(new_node);
  }

  node* pop(){
    node* now = this->top;
    if(not this->is_empty()){
      this->top = this->top->next;
    }
    this->size--;
    return now;
  }

  void show_stack(){
    if(this->is_empty()){
      cout << "the stack is empty" << endl;
      return;
    }
    node* now = this->top;
    while(now != nullptr){
      cout << now->val << " ";
      now = now->next;
    }
    cout << endl;
  }

  int count_top(int k){
    int count = 0;
    node* now = this->top;
    int val = now->val;
    for(int i = 0; i < k; i++){
      if(now->val == val){
        count++;
      }
      now = now->next;
    }
    return count;
  }
};


int main(){
  int n, k;
  cin >> n >> k;
  stack rock = stack();
  for(int i = 0; i < n; i++){
    int val;
    cin >> val;
    rock.push(val);
    if (rock.size >= k){
      int count = rock.count_top(k);
      if(count == k){
        for(int j = 0; j < k; j++){
          rock.pop();
        }
      }
    }
  }
  cout << rock.size << endl;
}