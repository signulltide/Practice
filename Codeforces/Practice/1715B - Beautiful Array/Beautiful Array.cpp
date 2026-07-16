#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    if (s < k*b || s > k*b+(k-1)*n) {
        cout << "-1\n";
        return;
    }
    vector<ll> res(n);
    res[0] = k*b;
    s -= res[0];
    for (ll i = 0; i < n; i++) {
        ll add = min(k - 1, s);
        res[i] += add;
        s -= add;
    }
    vout(res);
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}