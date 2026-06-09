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
        for (i=0; i<s; i++) {
            for (j=0; j<s*2; j++) {
                if (j == i) {
                    grid[i][j+offset] = '\\';
                } else if (j == s*2-i-1) {
                    grid[i][j+offset] = '/';
                } else {
                    grid[i][j+offset] = ' ';
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
