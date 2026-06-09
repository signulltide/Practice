#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int abs(int n) {
    if (n < 0) return n * -1;
    return n;
}

bool isInside(int y, int x, int s) {
    if (y >= 0 && y < s && x >= 0 && x < s) return true;
    return false;
}

pair<vector<vector<bool>>, vector<pair<int,int>>> search(vector<vector<bool>> grid, int y, int x, vector<pair<int,int>> queens) {
    grid[y][x] = true;
    //cout << "Placing queen at " << y << " " << x << endl;
    queens.push_back({y, x});
    int s = grid.size();
    for (int i=0; i<s; i++) {
        for (int j=0; j<s; j++) {
            if (!isInside(i, j, s)) continue;
            bool flag = true;
            for (auto &[qy, qx] : queens) {
                if (i == qy || j == qx || abs(qy-i) == abs(qx-j)) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                return search(grid, i, j, queens);
            }
        }
    }
    return {grid, queens};
}

int main() {
    int n, resCount = 0;
    cin >> n;
    cout << "[";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            vector<vector<bool>> grid(n, vector<bool>(n, false));
            auto [placedGrid, queens] = search(grid, i, j, {});
            if (queens.size() == 4) {
                if (resCount == 0) {
                    cout << "[";
                } else {
                    cout << ", [";
                }
                resCount++;
                for (int i=0; i<3; i++) {
                    cout << queens[i].second + 1 << ", ";
                }
                cout << queens[3].second + 1 << "]";
            }
        }
    }
    cout << "]";
}