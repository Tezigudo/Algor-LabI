#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long searchResult(vector<int> arr, int n, int g, int t) {
    long long result = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        int s = arr[l] + arr[r];
        if (s < g - t) {
            l++;
        } else if (s > g + t) {
            r--;
        } else {
            result++;
            l++;
            r--;
        }
    }
    return result;
}

int main() {
    int n, g, t;
    cin >> n >> g >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << searchResult(arr, n, g, t) << endl;
    return 0;
}
