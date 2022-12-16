// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// const int MAX_N = 100010;

// int n;
// int s[MAX_N], t[MAX_N];
// vector<pair<int, int> > items;

// void read_input() {
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> s[i] >> t[i];
//         items.push_back(make_pair(t[i], i));
//     }
// }

// int main() {
//     read_input();
//     sort(items.begin(), items.end());
//     int summa = 0;
//     int now_end = 0;
//     for (int i = 0; i < n; i++) {

//         if(s[i] >= now_end){
//             now_end = items[i].first;
//             summa++;
//             cout << items[i].second << "   " << i <<endl;
//         }
//     }
//     cout << summa << endl;
//     return 0;
// }

#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

class Interval {
   public:
    int start, finish;

    bool operator<(const Interval& x) const {
        if (finish != x.finish) return finish < x.finish;
        return start < x.start;
    }
}* intervals;

int main() {
    int N, i, last_finished;

    scanf("%d", &N);  // Number of intervals
    intervals = new Interval[N];
    for (i = 0; i < N; i++)
        scanf("%d %d", &intervals[i].start, &intervals[i].finish);

    // sort intervals in non-decreasing order of finish times
    sort(intervals, intervals + N);

    queue<int> opt;
    // construct the optimal solution
    for (i = 0, last_finished = 0; i < N; i++)
        if (intervals[i].start >= last_finished) {
            opt.push(i);
            last_finished = intervals[i].finish;
        }

    // optimal solution
    int s = 0;
    while (!opt.empty()) {
        i = opt.front();
        opt.pop();
        s++;
    }
    printf("%d", s);

    return 0;
}