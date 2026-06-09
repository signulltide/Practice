#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> grid;
int h = 0, w = 0;

void Imprint(int pos, int size) {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size*2; j++) {
            if (j>size-1-i && j<size+i) {
                grid[h-size+i][pos-1+j] = 'X';
            } else if (j==size-1-i) {
                if (grid[h-size+i][pos-1+j] == '\\') {
                    grid[h-size+i][pos-1+j] = 'v';
                } else if (grid[h-size+i][pos-1+j] != 'X') {
                    grid[h-size+i][pos-1+j] = '/';
                }
            } else if (j==size+i) {
                if (grid[h-size+i][pos-1+j] == '/') {
                    grid[h-size+i][pos-1+j] = 'v';
                } else if (grid[h-size+i][pos-1+j] != 'X') {
                    grid[h-size+i][pos-1+j] = '\\';
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> mountainPos;
    vector<int> mountainSize;
    int n, a, b;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        if (b > h) h = b;
        if (a + b * 2 - 1 > w) w = a + b * 2 - 1;   
        mountainPos.push_back(a);
        mountainSize.push_back(b);
    }
    grid.resize(h, vector<char>(w, '.'));
    for (int i=0; i<n; i++) {
        Imprint(mountainPos[i], mountainSize[i]);
    }
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}