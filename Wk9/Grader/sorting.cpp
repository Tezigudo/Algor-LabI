#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    long int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    } 
    sort(arr, arr+n);
    for (int i=k-1;i<n;i+=k){
        cout << arr[i] << endl;
    }
    return 0;
}