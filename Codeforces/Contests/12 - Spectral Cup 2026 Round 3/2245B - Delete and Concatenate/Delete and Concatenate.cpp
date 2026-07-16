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
    ll n, c;
    cin >> n >> c;
    vector<ll> arr(n);
    vin(arr);
    ll score = 0;
    for (ll i=0; i<n; i++) {
        score += arr[i] - c;
    }
    sort(arr.begin(), arr.end());
    for (ll i=0; i<n/2; i++) {
        if (c - arr[i] >= 0) {
            score += c - arr[i];
        }
    }
    cout << score << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}