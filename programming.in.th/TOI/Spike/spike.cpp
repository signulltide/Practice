#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, i, j, h, most = 0, sum = 0;
    vector<int> height;

    for (i=0; i<n; i++) {
        cin >> h;
        if (h > most) {
            most = h;
        }
        sum += h;
        height.push_back(h);
    }

    //vector<vector<char>> grid(most, vector<int>(sum*2))
}