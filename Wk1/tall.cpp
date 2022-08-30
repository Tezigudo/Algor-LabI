// #include <iostream>
// #include <algorithm>

// using namespace std;

// int index(int arr[], int item, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == item)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// void sort(int arr[], int size){

//     for (int i=1; i<=size-1;i++){
//         for (int j=0;j<=size-1-i;i++){
//             if (arr[i] > arr[i+1]){
//                 swap(arr[i], arr[i+1]);
//             }
//         }
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n], unique[n];
//     int count = 0;

//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         arr[i] = x;
//         if (index(unique, x, n) == -1)
//         {
//             unique[i] = x;
//             count += 1;
//         }
//     }

//     sort(unique, count);
//     for(int i=0;i<count;i++){
//         cout << unique[i];
//     }
//     cout << endl;

//     for (int j = 0; j < n; j++){
//         cout << count - index(unique, arr[j], count)-1 << endl;
//     }
// }

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(arr[i]<arr[j]){
                count++;
            }
        }
        cout << count << endl;
    }
}