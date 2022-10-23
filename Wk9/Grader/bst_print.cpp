#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

struct node {
  int val;
  node* left;
  node* right;
  int level;
  node(int value, int levelel, node* left_node = nullptr, node* right_node = nullptr) {
    this->val = value;
    this->level = levelel;
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

void insert(node*& r, int x, int level=-1) {
  if (!r) {
    r = new node(x, level);
  } else if (x < r->val) {
    insert(r->left, x, level+1);
  } else if (x > r->val) {
    insert(r->right, x, level+1);
  }
}

void inorder(node* root){
    if(!root){
        return;
    }
    inorder(root->right);
    for(int i=0;i<=root->level; i++){
        cout<<"...";
    }
    cout << "* " << root->val << endl;
    inorder(root->left);
}
int main(){
  int n;
  cin >> n;
  node* root = nullptr;
  while(n--){
    int x;
    cin >> x;
    insert(root, x);
  }
  inorder(root);
}