#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vCount, eCount, u, v, w;
    cin >> vCount >> eCount;
    vector<vector<int>> dist(vCount, vector<int>(vCount, 1e8));
    for (int i=0; i<eCount; i++) {
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    for (int i=0; i<vCount; i++) {
        dist[i][i] = 0;
    }
    for (int k=0; k<vCount; k++) {
        for (int i=0; i<vCount; i++) {
            for (int j=0; j<vCount; j++) {
                if (i==j) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i=0; i<vCount; i++) {
        for (int j=0; j<vCount; j++) {
            cout << dist[i][j] << "\t\t";
        }
        cout << endl;
    }
}