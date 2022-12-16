#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> arr;
        int m = 0;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end());
        int start = arr.front();
        int end = arr.back();
        cin >> m;
        for (int i = 0; i < n; i++) {
            int tmp = arr[i];
            int tmptmp = m-tmp;
            if (tmp > tmptmp){
                break;
            }
            if (binary_search(arr.begin() + i + 1, arr.end(), tmptmp)) {

                if (tmptmp-tmp < end-start) {
                    start = tmp;
                    end = tmptmp;

                }

            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n",
        start, end); string blankline; getline(cin, blankline);
    }

    return 0;
}