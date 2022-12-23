#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int minimum_maximum_penalty(vector<pair<int, int>> jobs) {
    // sort the jobs in increasing order of their duration
    sort(jobs.begin(), jobs.end(),
         [](auto &a, auto &b) { return a.second < b.second; });

    int current_day = 0;
    int max_penalty = 0;

    // iterate through the sorted list of jobs
    for (auto job : jobs) {
        int deadline = job.first;
        int duration = job.second;
        if (current_day + duration > deadline) {
            // calculate the penalty
            int penalty = (current_day + duration - deadline - 10) * 1000;
            max_penalty = max(max_penalty, penalty);
        } else {
            current_day += duration;
        }
    }

    return max_penalty;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++) {
        int deadline, duration;
        cin >> deadline >> duration;
        jobs.push_back({deadline, duration});
    }
    cout << minimum_maximum_penalty(jobs) << endl;
    return 0;
}
