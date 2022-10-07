#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;


int main(){
    int n, s, t, count=0;
    cin >> n >> s >> t;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]>=s and abs(arr[i]-arr[j]) <= t){
                // cout << arr[i] << ", " << arr[j] << endl;
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
// * 90 [ PPPPPPPPPT ]