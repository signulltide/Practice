#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, temp;
    cin >> n;
    vector<pair<ll, ll>> arr; // val, index
    for (ll i=0; i<n; i++) {
        cin >> temp;
        arr.push_back({temp, i});
    }
    sort(arr.begin(), arr.end());
    vector<ll> pref(n);
    pref[0] = arr[0].first;
    for (ll i=1; i<n; i++) {
        pref[i] = pref[i-1] + arr[i].first;
    }
    vector<ll> ans(n, 0), res(n);
    ans[n-1] = n-1;
    res[arr[n-1].second] = n-1;
    for (ll i=n-2; i>=0; i--) {
        if (pref[i] >= arr[i+1].first) {
            ans[i] = ans[i+1];
        } else {
            ans[i] = i;
        }
        res[arr[i].second] = ans[i];
    }
    vout(res);
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