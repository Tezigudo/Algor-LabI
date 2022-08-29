#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++){
        arr[i] = i+1;
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n+i;j++){
            cout << arr[j%n];
        }

        cout << endl;

    }
}