#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dfs(map<int, vector<int>> adj, map<int, int> &vis, int cv) {
    cout << cv;
    vis[cv] = 1;
    for (int v : adj[cv]) {
        if (!vis[v]) {
            dfs(adj, vis, v);
        }
    }
}

int main() {
    map<int, vector<int>> adjList;
    map<int, int> visited;
    int n, a, b, least = 10001;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        visited[a] = 0;
        visited[b] = 0;
        if (a < least) least = a;
        if (b < least) least = b;
    }
    if (least != 10001) {dfs(adjList, visited, least);} else {cout << "what?";}
}