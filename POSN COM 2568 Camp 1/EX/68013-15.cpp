#include <iostream>
#include <vector>
using namespace std;

int main() {
    int i, j, spikeCount, s, most = 0, sum = 0;
    vector<int> spikes;
    cin >> spikeCount;
    for (i=0; i<spikeCount; i++) {
        cin >> s;
        if (s > most) {
            most = s;
        }
        sum += s;
        spikes.push_back(s);
    }

    vector<vector<char>> grid(sum*2, vector<char>(most, ' '));

    int offset = 0;

    for (int s : spikes) {
        for (i=0; i<s*2; i++) {
            for (j=0; j<s; j++) {
                if (i < s) {
                    if (j == s-i-1) {
                        grid[i+offset][most-s+j] = '/';
                    }
                } else {
                    if (j == i-s) {
                        grid[i+offset][most-s+j] = '\\';
                    }
                }
            }
        }
        offset += s*2;
    }

    for (i=0; i<sum*2; i++) {
        for (j=0; j<most; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

}