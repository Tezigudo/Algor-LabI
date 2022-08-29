#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_prime(int n){
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int next_prime(int n){
    if (is_prime(n)){
        n++;
    }
    while (!is_prime(n)){
        n++;
    }
    return n;
}
int main(){
    int n;
    cin >> n;
    cout << next_prime(n);
}