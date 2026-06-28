#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, k;
    cin >> n >> k;
    ll res = 0, cost = 1;
    while (cost <= n) {
        ll take = min(k, n / cost);
        res += take;
        n -= take * cost;
        cost *= 2;
    }
    cout << res << '\n';
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}