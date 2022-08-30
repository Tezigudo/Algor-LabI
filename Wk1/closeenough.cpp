#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int N, L;
    cin >> N >> L;
    int house[N];
    int count = 0;

    for (int i=0; i<N; i++){
        int x;
        cin >> x;
        house[i] = x;
    }

    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(i!=j){
                if (abs(house[i]-house[j]) <=L){
                    count++;
                }
            }
        }
    }
    cout << count;
}