#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

int main(){
    int g;
    do{
    string s;
    cin >> g;
    if(g == 0){
        break;
    }
    cin  >> s;
    int time=s.size()/g;
    for(int i=0; i<s.size(); i+=time){
        reverse(s.begin()+i, s.begin()+i+time);
    }
    cout << s<< endl;
    }while(g != 0);

    return 0;
}