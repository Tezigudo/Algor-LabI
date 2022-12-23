#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

// void extractVal(map<int, int> &m, int x){
//     int i = 0;
//     while(x > 0){
//         int val = x % 10;
//         m[val] ++;
//         x /= 10;
//         i++;
//     }
// }

int main(){
    int n;
    cin >> n;
    int arr[n];
    map<int, int> m;
    for(int i=0;i<10;i++){
        m[i] = 0;
    }
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=1;i<n;i++){
        int x = abs(arr[i] - arr[i-1]);
        // cout << x << endl;
        m[x]++;
    }

    for(int i=2;i<n;i++){
        int x = abs(arr[i] - arr[i-2]);
        // extractVal(m, x);
        m[x]++;
    }

    int maxi = 0;
    for(int i=9;i>=0;i--){
        // cout << m[i] << " ";
        maxi = max(m[i], maxi);
    }

    cout << maxi << endl;
    return 0;
}