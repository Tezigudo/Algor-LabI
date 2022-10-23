#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int minima = INFINITY;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i=1;i<n;i++){
        minima = min(minima, abs(arr[i]-arr[i-1]));
    }
    cout << minima;
    return 0;
}