#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, i, j, k, r, s, c, mostR = 0, remaining = 0, mostCount = 0;
    vector<int> row, start, count;

    cin >> n;

    for (i=0; i<n; i++) {
        cin >> r >> s >> c;
        row.push_back(r-1);
        start.push_back(s-1);
        count.push_back(c);
        if (r > mostR) {mostR = r;}
    }

    for (i=0; i<mostR; i++) {
        for (j=0; j<70; j++) {
            for (k=0; k<n; k++) {
                if (row[k] == i && start[k] == j) {
                    if (remaining < count[k]) {
                        remaining = count[k];
                    }
                }
            }
            if (remaining > 0) {
                cout << "x";
                remaining--;
            } else {
                cout << "o";
            }
        }
        cout << endl;
        remaining = 0;
    }

    return 0;
}