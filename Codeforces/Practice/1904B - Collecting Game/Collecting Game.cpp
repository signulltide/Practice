#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, temp;
    cin >> n;
    vector<ll> arr(n), prefixSum;
    vector<ll> sorted;
    for (ll i=0; i<n; i++) {
        cin >> temp;
        arr[i] = temp;
        sorted[i] = temp;
    }

    sort(sorted.begin(), sorted.end());

    prefixSum.push_back(sorted[0]);
    for (ll i=1; i<n; i++) {
        prefixSum.push_back(prefixSum[i-1] + sorted[i]);
    }

    for (ll i=0; i<n; i++) {
        auto lower = lower_bound(sorted.begin(), sorted.end(), prefixSum[find(sorted.begin(), sorted.end(), arr[i]) - sorted.begin()]) - sorted.begin();
        // WHAT THE FUCK??
    }
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