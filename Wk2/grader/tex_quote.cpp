#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    string quote[] = {"``", "''"};
    string line;
    int index = 0, count = 0;
    while(getline(cin, line)){
        for(int i=0;i<line.length();i++){
            if (line[i] == '"'){
                cout << quote[index];
                count+=1;
                if (count==2){
                    index = (index+1)%2;
                    count = 0;
                }
            }else{
                cout << line[i];
            }
        }
    }
    return 0;
}