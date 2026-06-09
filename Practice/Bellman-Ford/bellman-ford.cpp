#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int vertexCount, edgeCount, u, v, w;
    cin >> vertexCount >> edgeCount;
    vector<vector<pair<int, int>>> adjList(edgeCount); // v, w
    vector<int> dist(vertexCount, INT_MAX);
    for (int i=0; i<edgeCount; i++) {
        cin >> u >> v >> w;
        u--; v--;
        adjList[u].push_back({v, w});
    }
    int src;
    cin >> src;
    dist[src] = 0;
    for (int i=0; i<vertexCount; i++) {
        for (int u=0; u<vertexCount; u++) {
            if (dist[u] == INT_MAX) continue;
            for (auto &[v, w] : adjList[u]) {
                if (dist[u] + w < dist[v]) {
                    if (i == vertexCount - 1) {
                        cout << "Negative Cycle.";
                        return 0;
                    } // negative cycle detection (normal graphs can only be relaxed v-1 times max)
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    for (int i=0; i<vertexCount; i++) {
        cout << i << " = " << dist[i] << endl;
    }
}