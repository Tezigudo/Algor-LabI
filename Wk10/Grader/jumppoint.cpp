#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = 100010;

int n, r;

int arr_x[MAX_N];
int arr_y[MAX_N];

double distance(int x0, int x1, int y0, int y1) {
    return sqrt((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0));
}

vector<int> adj[MAX_N];


bool seen[MAX_N];
int layer[MAX_N];

int deg[MAX_N];

void read_input(){
        cin >> n >> r;
    arr_x[0] = 0;
    arr_y[0] = 0;
    arr_x[n+1] = 100;
    arr_y[n+1] = 100;


    for (int i = 1; i < n + 1; i++) {
        int x, y;
        cin >> arr_x[i] >> arr_y[i];
    }

    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            double dist = distance(arr_x[i], arr_x[j], arr_y[i], arr_y[j]);
            if (dist<= r) {
                adj[i].push_back(j);
                adj[j].push_back(i);

                deg[i]++;
                deg[j]++;
            }
        }
    }

}

void init() {
    for (int u = 0; u < n; u++) {
        seen[u] = false;
        layer[u] = -1;
    }
}

void bfs(int s) {
    list<int> Q;

    Q.push_back(s);
    seen[s] = true;
    layer[s] = 0;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        for (int d = 0; d < deg[u]; d++) {
            int v = adj[u][d];
            if (!seen[v]) {
                Q.push_back(v);
                seen[v] = true;
                layer[v] = layer[u] + 1;
            }
        }
    }
}

int main() {
    read_input();
    init();
    bfs(0);
    if (!seen[n + 1]) {
        cout << -1 << endl;
    } else {
        cout << layer[n + 1] << endl;
    }
}