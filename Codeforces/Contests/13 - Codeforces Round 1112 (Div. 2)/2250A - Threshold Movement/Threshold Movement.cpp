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
    vector<ll> arr(n), sorted(n);
    vin(arr);

    if (n%2 == 1) {
        cout << "NO\n";
        return;
    }

    sorted = arr;
    sort(sorted.begin(), sorted.end());

    if (sorted[n/2] - sorted[n/2-1] <= 1) {
        cout << "NO\n";
        return;
    }

    ll mid = (sorted[n/2] + sorted[n/2-1]) / 2;

    for (ll i=0; i<n; i++) {
        if (arr[i] < mid && i % 2 == 0) {
            cout << "NO\n";
            return;
        } else if (arr[i] > mid && i % 2 == 1) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}