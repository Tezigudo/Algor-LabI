#include <iostream>
#include <algorithm>


using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b); //algor in discrete math class
    // it mean a if b==0 else will recursively call gcd(b, a%b)
}

int main(){
    int a, b;
    cin >> a >> b;
    int ggccdd = gcd(a, b);
    cout << a/ggccdd << '/' << b/ggccdd;
}


//bell's code
// #include <iostream>
// using namespace std;
// int main(){
//     int gcd, a, b;
//     int x, y;
//     cin >> a >> b;
//     gcd = 1;
//     if (a < b){
//         x = a;
//         y = b;
//     }
//     else{
//         x = b;
//         y = a;
//     }
//     for (int i = 1; i <=x; i++){
//         if ((x % i == 0) && (y % i == 0))
//         {
//             gcd = i;
//         }
//     }
//         cout << a / gcd << "/" << b / gcd;
// }