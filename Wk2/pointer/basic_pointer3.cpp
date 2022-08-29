#include <iostream>
using namespace std;

void dosomething(int *a) {
    int arr[100];
    // int *temp = arr;
    //  *a = *temp;
    
    }

int main() {
    int* x = 0;
    cout << x;

    dosomething(x);
    for (int i = 0; i < 100; i++) {
      x[i] = i * 2;
    }
    cout << x[1] + x[20] + x[99] << endl;

    delete[] x;
}
