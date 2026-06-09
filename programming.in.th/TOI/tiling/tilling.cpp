#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int s;
vector<vector<int>> grid;
vector<vector<int>> visited;
vector<pair<int,int>> latest;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isInside(int y, int x) {
    if (y >= 0 && y < s && x >= 0 && x < s) {
        return true;
    } else {
        return false;
    }
}

bool CheckLatestValidity() {
    bool yFlag = true, xFlag = true;
    int py = latest[0].first, px = latest[0].second;
    for (int i=1; i<latest.size(); i++) {
        if (latest[i].first != py) {
            yFlag = false;
        }
        if (latest[i].second != px) {
            xFlag = false;
        }
        py = latest[i].first; px = latest[i].second;
    }
    if (yFlag || xFlag) {
        return false;
    } else {
        return true;
    }
}

int CheckConnecting(int y, int x) {
    latest.push_back({y, x});
    visited[y][x] = 1;
    int count = 1;
    for (int d=0; d<4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (isInside(ny, nx) && !visited[ny][nx] && grid[y][x] == grid[ny][nx]) {
            count += CheckConnecting(ny, nx);
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    grid.resize(s, vector<int>(s));
    visited.resize(s, vector<int>(s));

    int correct = 0;

    for (int i=0; i<s; i++) {
        for (int j=0; j<s; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i=0; i<s; i++) {
        for (int j=0; j<s; j++) {
            if (!visited[i][j]) {
                if (CheckConnecting(i, j) == 3 && CheckLatestValidity()) {
                    correct++;
                    latest.clear();
                }
            }
        }
    }

    cout << correct;
}