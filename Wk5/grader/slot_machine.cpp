#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

struct node {
    int value;
    node *next;
    node(int val, node* next_node=nullptr){
        value = val;
        next = next_node;
    }
};

struct  queue
{
    
};


void insert(node* head, int val){
    node* new_node = new node(val);
    while(head->next != nullptr){
        head = head->next;
    }
    head->next = new_node;
}

void show_slot(node*head[]){
    for(int i=0; i<4; i++){
        node* temp = head[i];
        while(temp->next != nullptr){
            temp = temp->next;
            cout << temp->value << " ";
        }
        cout << endl;
    }
}

int point(node* head[]){
    int point = 0;
    for(int i=0; i<4; i++){
        node* temp = head[i];
        while(temp->next != nullptr){
            temp = temp->next;
            if(temp->value == 7){
                point += 1;
            }
        }
    }
    return point;
}



int main(){
    node* head0 = new node(0);
    node* head1 = new node(0);
    node* head2 = new node(0);
    node* head3 = new node(0);
    node* head[4] = {head0, head1, head2, head3};
    for(int i =0;i<4;i++){
        for(int j=0;j<4;j++){
            int val;
            cin >> val;
            insert(head[j], val);
        }
    }


    show_slot(head);
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