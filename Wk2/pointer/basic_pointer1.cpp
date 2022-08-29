#include <iostream>
using namespace std;

int main()
{

    int a[5] = {1, 2, 3, 4, 5};

    int *p = a;

    cout << *p << endl;
    cout << *p+3 << endl;

    p += 3;

    cout << *p << endl;
    cout << *(p-1) << endl;

    int *q = &a[5];

    cout << a << endl;
    cout << p << endl;
    cout << *q << endl;
    return 0;
}

#include<iostream>
using namespace std;

int main(){
    int arr[4] = {1, 2, 3, 4};
    int *ptr = &arr[4];
    int *q = arr;
    cout << &q << endl;
    cout << ptr-1  << endl;
    return 0;
}

// #include<iostream>
// using namespace std;

// int main(){
//     int *banana;
//     *banana = 5;
//     cout << &banana;
//     return 0;
// }