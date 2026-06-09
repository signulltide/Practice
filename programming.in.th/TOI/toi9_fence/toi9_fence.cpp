#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define ll long long int

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll y, x, t, a, b;
    vector<int> res(2);
    for (ll k=0; k<2; k++) {
        cin >> y >> x;
        vector<vector<ll>> grid(y, vector<ll>(x, 0)), trees(y, vector<ll>(x, 0));
        cin >> t;
        for (ll i=0; i<t; i++) {
            cin >> a >> b;
            grid[a][b] = 1;
        }
        trees[0][0] = grid[0][0];
        for (ll i=1; i<y; i++) {
            trees[i][0] = grid[i][0] + trees[i-1][0];
        }
        for (ll j=1; j<x; j++) {
            trees[0][j] = grid[0][j] + trees[0][j-1];
        }
        for (ll i=1; i<y; i++) {
            for (ll j=1; j<x; j++) {
                trees[i][j] = grid[i][j] + trees[i-1][j] + trees[i][j-1] - trees[i-1][j-1];
            }
        }
        bool found = false;
        for (ll currentSize = min(y, x); currentSize>0; currentSize--) {
            for (ll i=0; i<=y-currentSize; i++) {
                for (ll j=0; j<=x-currentSize; j++) {
                    ll y2 = i+currentSize-1;
                    ll x2 = j+currentSize-1;
                    ll e1, e2, ad;
                    if (i==0 && j==0) {
                        e1 = 0; e2 = 0; ad = 0;
                    } else if (i==0) {
                        e1 = trees[y2][j-1]; e2 = 0; ad = 0;
                    } else if (j==0) {
                        e1 = 0; e2 = trees[i-1][x2]; ad = 0;
                    } else {
                        e1 = trees[y2][j-1]; e2 = trees[i-1][x2]; ad = trees[i-1][j-1];
                    }
                    ll outer = trees[y2][x2] - e1 - e2 + ad;
                    ll inner;
                    if (currentSize <= 2) {
                        inner = 0;
                    } else {
                        inner = trees[y2-1][x2-1] - trees[y2-1][j] - trees[i][x2-1] + trees[i][j];
                    }
                    if (outer == inner) {
                        res[k] = currentSize;
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            if (found) break;
        }
    }
    cout << res[0] << endl << res[1];
}