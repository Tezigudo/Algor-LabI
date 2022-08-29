#include <iostream>

using namespace std;


int digit(int num){
    int dig = 0;
    do{
        dig++;
        num/=10;
    }while(num!=0);
    return dig;
}

bool is_palindrome(int arr[], int size){
    int mid = size/2;
    for (int i=0;i<mid;i++){ //4-> mid=2 0 1 3 2
        if(arr[i]!=arr[size-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    int dig = digit(n);
    int arr[dig];

    int i=0;
    do{
        arr[i] = n%10;
        n/=10;
        i++;
    }while(n!=0);

    cout << (is_palindrome(arr, dig)? "yes": "no");
}