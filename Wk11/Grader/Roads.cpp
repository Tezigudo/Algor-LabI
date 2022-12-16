// #include <algorithm>
// #include <cstring>
// #include <iostream>
// #include <list>
// #include <map>
// #include <string>
// #include <vector>

// using namespace std;

// bool bfs(int s, int start, int target, vector<pair<int, int> > adj[], int n) {
//     // init bfs
//     bool seen[n];
//     memset(seen, false, n);

//     list<int> Q;
//     Q.push_front(start);
//     seen[start] = true;

//     while (!Q.empty()) {
//         int u = Q.front();
//         Q.pop_front();

//         for (auto path : adj[u]) {
//             int v = path.first;
//             int speed = path.second;

//             if (!seen[v]) {
//                 seen[v] = true;
//                 cout << "visited: " << v + 1 << endl;
//                 cout << "at minimum speed: " << speed << endl;
//                 if (v == target && speed <= s) {
//                     return true;
//                 }
//                 if (speed <= s) {
//                     Q.push_front(v);
//                 }
//             }
//         }
//     }

//     return false;
// }

// int main() {
//     int n, m, s, q;
//     cin >> n >> m >> s >> q;

//     // initialize graph
//     // pair of edges that connect to and speed limit respectively
//     vector<pair<int, int> > adj[n];

//     for (int i = 0; i < m; i++) {
//         // makegraph
//         int x, y, l;
//         cin >> x >> y >> l;
//         x--;
//         y--;

//         adj[x].push_back(make_pair(y, l));
//         adj[y].push_back(make_pair(x, l));
//     }
//     for (int i = 0; i < q; i++) {
//         int start, target;
//         cin >> start >> target;
//         start--;
//         target--;
//         cout << "Finding: " << target + 1 << endl;
//         cout << "starting at: " << start + 1 << endl;
//         cout << (bfs(s, start, target, adj, n) ? "yes" : "no") << endl;
//         cout << endl;
//     }

//     return 0;
// }


#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool bfs(int s, int start, int target, vector<pair<int, int> > adj[], int n) {
    // init bfs
    bool seen[n];
    memset(seen, false, n);

    list<int> Q;
    Q.push_front(start);
    seen[start] = true;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop_front();

        for (auto path : adj[u]) {
            int v = path.first;
            int speed = path.second;
            if (!seen[v]) {
                seen[v] = true;

                if(v==target && speed <= s){
                    return true;
                }
                if(speed <= s){
                    Q.push_front(v);
                }
            }
        }
    }

    return false;
}

int main() {
    int n, m, s, q;
    cin >> n >> m >> s >> q;

    // initialize graph
    // pair of edges that connect to and speed limit respectively
    vector<pair<int, int> > adj[n];

    for (int i = 0; i < m; i++) {
        // makegraph
        int x, y, l;
        cin >> x >> y >> l;
        x--;
        y--;

        adj[x].push_back(make_pair(y, l));
        adj[y].push_back(make_pair(x, l));
    }
    for (int i = 0; i < q; i++) {
        int start, target;
        cin >> start >> target;
        start--;
        target--;
        cout << (bfs(s, start, target, adj, n) ? "yes" : "no") << endl;
    }

    return 0;
}