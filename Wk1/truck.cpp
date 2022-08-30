#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr[i] = x;
    }

    int bus = 0;
    int peep = 0;
    for(int i=0;i<n;i++){
        if(peep + arr[i] >1000){
            bus++;
            peep = arr[i];
        }else{
        peep += arr[i];
    }
        if(i==n-1 && peep!=0){
            bus++;
        }
    }
    cout << bus;

}
