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
    ll n;
    cin >> n;
    vector<ll> arr(n + 1);
    vector<ll> pref(n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
        pref[i] = pref[i - 1] + arr[i];
    }

    ll max_diff = 0;

    for (ll k = 1; k <= n; k++) {
        if (n % k != 0) continue;

        ll mn = LLONG_MAX;
        ll mx = 0;

        // Process each block of size k
        for (ll i = 1; i <= n; i += k) {
            ll current_sum = pref[i + k - 1] - pref[i - 1];
            mn = min(mn, current_sum);
            mx = max(mx, current_sum);
        }

        max_diff = max(max_diff, mx - mn);
    }

    cout << max_diff << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}