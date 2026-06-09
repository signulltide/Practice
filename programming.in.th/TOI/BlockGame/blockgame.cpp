#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector<vector<char>> grid;
int w, h, destroyed = 0, score = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool Inside(int y, int x) {
    if (y >= 0 && y < h && x >= 0 && x < w) {
        return true;
    } else {
        return false;
    }
}

void ApplyGravity() {
    for (int x=0; x<w; x++) {
        for (int y=h-2; y>=0; y--) {
            if (grid[y][x] != '-' && grid[y][x] != '#') {
                int ny = y;
                while (Inside(ny, x) && grid[ny+1][x] == '-')
                    ny++;
                if (ny != y){
                    grid[ny][x] = grid[y][x];
                    grid[y][x] = '-';
                }
            }
        }
    }
}

bool RemoveGroup() {
    vector<vector<char>> visited(h, vector<char>(w, 0));
    bool removed = false;

    for (int y=0; y<h; y++) {
        for(int x=0; x<w; x++) {    
            if (grid[y][x] == '-' || grid[y][x] == '#' || visited[y][x]) continue;
            char c = grid[y][x];

            queue<pair<int,int>> upNext;
            vector<pair<int,int>> group;

            upNext.push({y,x});

            while (!upNext.empty()) {
                auto [cy, cx] = upNext.front();

                group.push_back({cy, cx});
                upNext.pop();
                visited[cy][cx] = 1;

                for (int d=0; d<4; d++) {
                    int nx = cx + dx[d];
                    int ny = cy + dy[d];
                    if (Inside(ny, nx) &&!visited[ny][nx] && grid[ny][nx] == c) {
                        upNext.push({ny, nx});
                    }
                }
            }

            if (group.size() >= 2) {
                removed = true;
                score += group.size() * 5;
                for (auto &pos : group) {
                    grid[pos.first][pos.second] = '-';
                }
            }

        }
    }

    return removed;
}

void Cascade() {
    while (true) {
        ApplyGravity();
        if (RemoveGroup() == false) break;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> h >> w;
    grid.resize(h, vector<char>(w, '-'));

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> grid[i][j];
        }
    }

    int commandCount;
    cin >> commandCount;
    for (int i=0; i<commandCount; i++) {
        int y, x;
        char dir;
        cin >> y >> x >> dir;
        
        if (Inside(y, x) == false || grid[y][x] == '-' || grid[y][x] == '#') {
            //cout << "Selection not valid\n";
            score -= 5;
            continue;
        }

        int nx, ny;

        if (dir == 'L') {
            nx = x-1;
        } else if (dir == 'R') {
            nx = x+1;
        }

        if (Inside(y,nx) == false || grid[y][nx] != '-') {
            //cout << "Target not valid\n";
            score -= 5;
            continue;
        }

        //cout << "Valid\n";

        char original = grid[y][x];
        grid[y][x] = '-';
        ny = y;

        while (Inside(ny+1,nx) && grid[ny+1][nx] == '-') {
            ny++;
        }

        grid[ny][nx] = original;

        Cascade();

    }

    cout << score << endl;

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    
}