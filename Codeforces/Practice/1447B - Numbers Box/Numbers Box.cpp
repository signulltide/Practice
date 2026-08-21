#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> grid(n, vector<ll>(m));
    ll least = LLONG_MAX, total = 0, neg_count = 0;
    for (ll i=0; i<n; i++) {
        for (ll j=0; j<m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] < 0) neg_count++;
            total += abs(grid[i][j]);
            least = min(least, abs(grid[i][j]));
        }
    }
    if (neg_count % 2 == 1) total -= least * 2;
    cout << total << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}