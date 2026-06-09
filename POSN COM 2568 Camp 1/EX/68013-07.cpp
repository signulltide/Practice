#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, i, j, ts, most = 0, sum = 0;
    vector<int> sizes;
    cin >> n;
    for (i=0; i<n; i++) {
        cin >> ts;
        if (ts > most) {
            most = ts;
        }
        sum += ts;
        sizes.push_back(ts);
    }
    vector<vector<char>> grid(most, vector<char>(sum*2, ' '));
    int offset = 0;
    for (int s : sizes) {
        for (i=s-1; i>=0; i--) {
            for (j=s*2-1; j>=0; j--) {
                if (j == i) {
                    grid[most-i-1][j+offset] = '/';
                } else if (j == s*2-i-1) {
                    grid[most-i-1][j+offset] = '\\';
                } else {
                    grid[most-i-1][j+offset] = ' ';
                }
            }
        }
        offset += s*2;
    }

    for (i=0; i<most; i++) {
        for (j=0; j<sum*2; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}
