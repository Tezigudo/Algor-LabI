#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int min(int arr[]){
    int minimum = 9999, ind=0;
    for(int i=0;i<5;i++){
        if(arr[i] < minimum){
            minimum = arr[i];
            ind = i;
        }
    }
    return ind;
}

int main(){
    int bucket[5];
    for(int i=0;i<5;i++){
        bucket[i] = 0;
    }
    int n, tank=0;
    cin >> n;
    while(n--){
        int k;
        cin >> k;
        int min_index = min(bucket);
        if (bucket[min_index]+k>=1000){
            bucket[min_index] = 0;
            tank+=1000;
        }else{
            bucket[min_index]+=k;
        }
    }
    cout << tank;
    return 0;
}
