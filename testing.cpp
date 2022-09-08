#include<iostream>
#include<cmath>
#include<algorithm>
#include <string>
using namespace std;

typedef struct Node{
    string name;
    int value;
} Node;

// int main(){
//     Node a = Node();
//     a.name = "banana";
//     a.value = 5;
//     cout << a.name;
//     return 0;
// }
int main(){
    string a;
    while (getline(cin, a)){
        cout << a << endl;
    }
}