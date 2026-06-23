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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    vin(arr);
    sort(arr.begin(), arr.end());
    ll streak = 1, best = 1;
    for (ll i=1; i<n; i++) {
        ll gap = arr[i] - arr[i-1];
        if (gap > k) {
            best = max(best, streak);
            streak = 1;
        } else {
            streak++;
        }
    }
    best = max(best, streak);
    cout << n - best << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}