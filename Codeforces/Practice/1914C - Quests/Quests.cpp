#include <iostream>
#include <vector>
using namespace std;

#define ll long long

void Solve() {
    ll n, k, total = 0, most = 0, res = 0;
    cin >> n >> k;
    vector<ll> first(n), sub(n);
    for (ll i=0; i<n; i++) {
        cin >> first[i];
    }
    for (ll i=0; i<n; i++) {
        cin >> sub[i];
    }
    for (ll i=0; i<min(n, k); i++) {
        total += first[i];
        most = max(most, sub[i]);
        res = max(res, total + ((k-i-1)*most));
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount;
    cin >> testCount;

    while (testCount--) {
        Solve();
    }

    return 0;
}