#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    cin >> n;
    vector<ll> a(2*n);
    vin(a);
    vector<ll> first(n+1, -1), dp(n*2, 0);
    for (ll i=0; i<2*n; i++) {
        if (first[a[i]] == -1) {
            first[a[i]] = i;
            if (i==0) continue;
            dp[i] = dp[i-1];
        } else {
            ll j = first[a[i]];
            ll L = i - j + 1;
            ll prev_i = (i > 0) ? dp[i-1] : 0;
            ll prev_j = (j > 0) ? dp[j-1] : 0;
            dp[i] = max(prev_i, prev_j + (L*L) - L);
        }
    }
    cout << (2*n) + dp[2*n-1] << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}