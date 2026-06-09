#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

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
    if (least == 10001) return 0;
    queue<int> q;
    q.push(least);
    while (!q.empty()) {
        int cv = q.front();
        q.pop();
        cout << cv << " ";
        visited[cv] = 1;
        for (int v : adjList[cv]) {
            if (!visited[v]) {
                q.push(v);
            }
        }
    }
}