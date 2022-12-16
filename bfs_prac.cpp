#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


int main() {
    int n = 5, m=5;

    vector<int> adj[n];
    for(int i=0;i<5;i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool seen[n];
    memset(seen, false, n);

    // lets bfs
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int u = q.front();
        q.pop();


        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            if(!seen[v]){

                seen[v] = true;
                q.push(v);
            }
        }
    }



    return 0;
}
/*
idx
{
0   [1, 2]
1  [0, 2]
2  [0, 1, 3]
3 [2, 4]
4 [3]
}
2 0 1 3 4

3 1 2 4 5
==================

=================

*/
