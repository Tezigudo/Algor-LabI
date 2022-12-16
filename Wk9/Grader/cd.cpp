#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int binary_serch(int arr[], int n, int x) {
    int l = 0;
    int r = n - 1;
    int mid = (l + r) / 2;
    while (l <= r) {
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
        mid = (l + r) / 2;
    }
    return -1;
}

int main() {
    while (1) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        int arr[n], s = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            if (binary_serch(arr, n, x) != -1) {
                s++;
            }
        }
        cout << s << endl;
    }
    return 0;
}