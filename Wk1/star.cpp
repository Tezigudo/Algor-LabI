#include <iostream>

using namespace std;

int main(){
    int x;
    cin >> x;

    for (int i=1;i<=x;i++){
        for(int j=x-i;j>0;j--){
            cout << " ";
        }

        for(int j=0;j<i;j++){
            cout << "*";
        }
        cout << endl;
    }
}