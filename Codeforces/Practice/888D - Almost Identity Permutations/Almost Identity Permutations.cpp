#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, k;
    cin >> n >> k;

    ll ans = 1; // j = 0
    if (k >= 2) {
        ans += n * (n - 1) / 2; // j = 2
    }
    if (k >= 3) {
        ans += 2 * (n * (n - 1) * (n - 2) / 6); // j = 3
    }
    if (k >= 4) {
        ans += 9 * (n * (n - 1) * (n - 2) * (n - 3) / 24); // j = 4
    }

    cout << ans << endl;
}

int main() {
    fastIO;

    Solve();

    return 0;
}