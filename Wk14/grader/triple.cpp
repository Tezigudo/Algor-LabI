#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(){
    map<int, int> m;
    for(int i = 0; i < 10; i++){
        m[i] = 0;
    }
    int n, counter=0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        m[x]++;
        if(m[x] == 3){
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}