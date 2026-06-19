#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, k, q, temp, streak = 0, res = 0;
    cin >> n >> k >> q;
    for (ll i=0; i<n; i++) {
        cin >> temp;
        if (temp <= q) {
            streak++;
        } else {
            if (streak >= k) res += ((streak - k + 1) * (streak - k + 2)) / 2;
            streak = 0;
        }
    }
    if (streak >= k) res += ((streak - k + 1) * (streak - k + 2)) / 2;
    cout << res << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) {
        Solve();
    }

    return 0;
}