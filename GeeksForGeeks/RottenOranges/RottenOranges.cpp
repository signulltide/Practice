#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

bool isInside(pair<int,int> p, vector<vector<int>> mat) {
    if (p.first >= 0 && p.first < mat.size() && p.second >= 0 && p.second < mat[0].size()) {
        return true;
    } else {
        return false;
    }
}    

int orangesRot(vector<vector<int>>& mat) {
    // code here
    int timeElasped = 0;
    int flag = false;
    
    queue<pair<int,int>> rotten;
    for (int i=0; i<mat.size(); i++) {
        for (int j=0; j<mat[0].size(); j++) {
            if (mat[i][j] == 2) {
                rotten.push({i, j});
            }
        }
    }
    
    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};
    
    while (!rotten.empty()) {
        flag = false;
        int layerSize = rotten.size();

        for (int i=0; i<layerSize; i++) {
            pair<int, int> c = rotten.front();
            rotten.pop();
            for (int d=0; d<4; d++) {
                pair<int,int> n = {c.first + dy[d], c.second + dx[d]};
                if (isInside(n, mat) && mat[n.first][n.second] == 1) {
                    flag = true;
                    mat[n.first][n.second] = 2;
                    rotten.push(n);
                }
            }
        }

        if (flag == true) {
            timeElasped++;
        }
    }
    
    for (int i=0; i<mat.size(); i++) {
        for (int j=0; j<mat[0].size(); j++) {
            if (mat[i][j] == 1) {
                return -1;
            }
        }
    }
    
    return timeElasped;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(m, vector<int>(n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> mat[i][j];
        }
    }
    cout << orangesRot(mat);
}