#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

struct node {
  int val;
  node* left;
  node* right;
  node(int value, node* left_node = nullptr, node* right_node = nullptr) {
    this->val = value;
    this->left = left_node;
    this->right = right_node;
  }
};

node* find(node* r, int x) {
    if(!r){
        return nullptr;
    }
  if (r->val == x) {
    return r;
  }
  if (x < r->val) {
    return find(r->left, x);
  }
  return find(r->right, x);
}

void insert(node*& r, int x) {
  if (!r) {
    r = new node(x);
  } else if (x < r->val) {
    insert(r->left, x);
  } else if (x > r->val) {
    insert(r->right, x);
  }
}

int main() { 
    int n;
    cin >> n;
    node* root = 0;
    while(n--){
        int k, x;
        cin >> k >> x;
        if(k==1){
            insert(root, x);
        }else{
            cout << (find(root, x)? 1: 0) << endl;
        }
    }
    
    return 0; }