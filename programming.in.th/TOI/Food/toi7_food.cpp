#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m, a;
    cin >> n >> m;
    vector<int> mFood, fFood, check(n+1, 0);
    for (int i=0; i<m; i++) {
        cin >> a;
        mFood.push_back(a);
        check[a] = 1;
    }
    for (int i=1; i<=n; i++) {
        if (check[i] == 0) {
            fFood.push_back(i);
        }
    }
    for (int i=0; i<n-m; i++) {
        int first = fFood[i];
        vector<int> curr = {first};
        for (int i=0; i<n-m; i++) {
            if (fFood[i] != first) {
                curr.push_back(fFood[i]);
            }
        }
        for (int i=0; i<m; i++) {
            curr.push_back(mFood[i]);
        }
        sort(curr.begin() + 1, curr.end());
        do {
            for (int i=0; i<n; i++) {
                cout << curr[i] << " ";
            }
            cout << "\n";
        } while (next_permutation(curr.begin() + 1, curr.end()));
    }
}