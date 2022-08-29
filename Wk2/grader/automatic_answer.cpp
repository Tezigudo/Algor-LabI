#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int k, n;
    cin >> k;
    while(k--){
        cin >> n;
        cout << abs(((n*567/9+7492)*235/47-498)/10%10) << endl;
    }
}