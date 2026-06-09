#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<double>> adjMat(n, vector<double>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> adjMat[i][j];
        }
    }
    int shallowest = INT_MAX, bestCurr = -1;
    for (int sc=0; sc<n; sc++) {
        queue<pair<int, pair<double, int>>> q; // currency, val, depth
        q.push({sc, {1.00, 0}});
        while (!q.empty()) {
            auto [cc, ci] = q.front(); q.pop();
            double cv = ci.first;
            double cd = ci.second;
            if (cd > n) continue;
            for (int nc=0; nc<n; nc++) {
                if (cc == nc) continue;
                double nv = cv * adjMat[cc][nc];
                if (nc == sc && nv > 1.01) {
                    int nd = cd + 1;
                    if (nd < shallowest) {
                        shallowest = nd;
                        bestCurr = cc;
                    }
                }
                q.push({nc, {cv * adjMat[cc][nc], cd + 1}});
            }
        }
    }
    cout << bestCurr << " " << shallowest;
    cout << -1;
}

